#pragma once
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <iostream>
#include <string>
#include <json/json.h>

#include "oj_log.hpp"
#include "tools.hpp"

enum ErrorNo
{
    //0 : 编译运行没有错误
    //1.编译错误
    //2.运行错误
    //3.参数错误
    //4.内存错误
    OK = 0,
    COMPILE_ERROR,
    RUN_ERROR,
    PRAM_ERROR,
    INTERNAL_ERROR

};

class Compiler
{
    public:
        //浏览器不同，URL编码原理不同，这里是谷歌浏览器编码方式
        //code="xxxx"&stdin="xxxx"
        static void CompilerAndRun(Json::Value Req,Json::Value* Resp)
        {
            if(Req["code"].empty())
            {
                (*Resp)["errorno"]=PRAM_ERROR;
                (*Resp)["reason"]="Pram error";
                LOG(ERROR,"Request Commande is Empty");
                return;
            }
        }
        //将代码写到文件当中
        std::string code=Req["code"].asString();
        //文件名称进行约定tep_时间戳.cpp
        std::string tmp_filename=WriteTempFile(code);
        if(tmp_filename=="")
        {
            (*Resp)["errorno"] = INTERNAL_ERROR;
            (*Resp)["reason"] = "Create file failed";
            LOG(ERROR, "Write Source failed");
            return;
        }

        //编译
        if(!Compile(tmp_filename))
        {
            (*Resp)["errorno"] = COMPILE_ERROR;
            std::string reason;
            FileOper::ReadDataFromFile(ErrorPath(tmp_filename), &reason);
            (*Resp)["reason"] = reason; 
            LOG(ERROR, "Compile Error") << std::endl;
            return;
        }
        //运行
        int sig=Run(tmp_filename);
        if(sig!=0)
        {
            (*Resp)["errorno"] = RUN_ERROR;
            (*Resp)["reason"] = "Program exit by sig " + std::to_string(sig);
            LOG(ERROR, "Run Error") << std::endl;
            return;
        }

        //构造响应
        (*Resp)["errorno"]=OK;
        (*Resp)["reason"]="Compile and Run is ok!";
        //标准输出
        std::string stdout_reason;
        FileOper::ReadDataFromFile(StdoutPath(tmp_filename), &stdout_reason);
        (*Resp)["stdout"] = stdout_reason;
        //标准错误
        std::string stderr_reason;
        FileOper::ReadDataFromFile(StderrPath(tmp_filename),&stderr_reason);
        (*Resp)["stderr"]=stderr_reason;

        //清理临时文件
        Clean(tmp_filename);
    private:
        //组织文件名称，组织文件的前缀名称，用来区分不同用户的源码文件
        static std::string WriteTempFile(const std::string& code)
        {
            std::string tmp_filename="/tmp_"+std::to_string(logTime::GetTimeStamp());
            //往文件里面写用户的代码数据
            int ret = FileOper::WriteDataToFile(SrcPath(tmp_filename), code); 
            if(ret < 0)
            {
                LOG(ERROR, "Write code to source failed");
                return "";

            }
            return tmp_filename;
        }
        static std::string SrcPath(const std::string& filename)
        {
            return "./tmp_files" + filename + ".cpp";

        }

        static std::string ErrorPath(const std::string& filename)
        {
            return "./tmp_files" + filename + ".err";

        }

        static std::string ExePath(const std::string& filename)
        {
            return "./tmp_files" + filename + ".executable";

        }

        static std::string StdoutPath(const std::string& filename)
        {
            return "./tmp_files" + filename + ".stdout";

        }
        static std::string StderrPath(const std::string& filename)
        {
            return "./tmp_files" + filename + ".stderr";

        }

        //编译函数
        static bool Compile(const std::string& filename)
        {
            //构造编译命令-->g++ src -o exec文件 -std=c++11
            const int commandcount = 20;
            char buf[commandcount][50] = {{0}};
            char* Command[commandcount] = {0}; 
            for(int i = 0; i < commandcount; i++)
            {
                Command[i] = buf[i];

            }
            snprintf(Command[0], 49, "%s", "g++");
            snprintf(Command[1], 49, "%s", SrcPath(filename).c_str());
            snprintf(Command[2], 49, "%s", "-o");
            snprintf(Command[3], 49, "%s", ExePath(filename).c_str());
            snprintf(Command[4], 49, "%s", "-std=c++11");
            snprintf(Command[5], 49, "%s", "-D");
            snprintf(Command[6], 49, "%s", "CompileOnline");
            Command[7] = NULL;
            //创建子进程
            //子进程--进程替换g++命令行
            int pid = fork();
            if(pid < 0)
            {
                LOG(ERROR, "Create child process failed");
                return false;

            }
            else if(pid == 0)
            {
                int fd = open(ErrorPath(filename).c_str(), O_CREAT | O_RDWR, 0664);
                if(fd < 0)
                {
                    LOG(ERROR, "open Compile errorfile failed") << ErrorPath(filename) << std::endl;
                    exit(1);
                }
                //重定向
                dup2(fd,2);
                //程序替换
                execvp(Command[0],Command);
                perror("execvp");
                LOG(ERROR,"execvp failed")<<std::endl;
                exit(0);
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
            //验证是否生成可执行程序
            struct stat st; 
            int ret = stat(ExePath(filename).c_str(), &st);
            if(ret < 0)
            {
                LOG(ERROR, "Compile ERROR! Exe filename is ") << ExePath(filename) << std::endl;
                return false;

            }
            return true;
        }

        static int Run(std::string& filename)
        {
            //创建子进程
            //子进程替换编译出来的程序
            int pid=fork();
            if(pid<0)
            {
                LOG(ERROR,"Exec pragma failed! Create child process failed")<<std::endl;
                return -1;
            }
            else if(pid==0)
            {
                //获取：标准输出--重定向到文件
                int stdout_fd=open(StdoutPath(filename).c_str(),O_CREAT|O_RDWR,0664);
                if(stdout_fd<0)
                {
                    LOG(ERROR,"Open stdout file failed")<<std::endl;
                    return -1;
                }
                dup2(stdout_fd,1);
                //标准错误--重定向到文件
                int stderr_fd = open(StderrPath(filename).c_str(), O_CREAT | O_RDWR, 0664);
                if(stderr_fd < 0)
                {
                    LOG(ERROR, "Open stderr file failed") << StderrPath(filename) << std::endl;
                    return -1;

                }
                dup2(stdout_fd, 2);

                execl(ExePath(filename).c_str(), ExePath(filename).c_str(), NULL);
                exit(1);
            }
        }

        static void Clean(std::string filename)
        {
            unlink(SrcPath(filename).c_str());
            unlink(ExePath(filename).c_str());
            unlink(ErrorPath(filename).c_str());
            unlink(StdoutPath(filename).c_str());
            unlink(StderrPath(filename).c_str());
        }
};
