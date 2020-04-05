#pragma once 
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <cstdio>
#include <string>

//日志类
class LogTime
{
    public:
        static int64_t GetTimeStamp()
        {
            struct timeval tv;
            gettimeofday(&tv,NULL);
            return tv.tv_sec;
        }

        //返回 年-月-日 时:分:秒
        static void GetTimeStamp(std::string* TimeStamp)
        {
            time_t SysTime;
            time(&SysTime);
            struct tm* st=localtime(&SysTime);
            char buff[30]={0};
            snprintf(buff,sizeof(buff)-1,"%04d-%02d-%02d %02d:%02d:%02d",st->tm_year+1900,st->tm_mon+1,st->tm_mday,st->tm_hour,st->tm_min,st->tm_sec);
            TimeStamp->assign(buff,strlen(buff));
        }
};

//日志等级
const char* Level[]
{
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL",
    "DEBUG",
};

enum LogLevel
{
    INFO=0,
    WARNING,
    ERROR,
    FATAL,
    DEBUG
};

inline std::ostream& Log(LogLevel lev,const char* file,int line,const std::string& logmsg)
{
    std::string level_info=Level[lev];
    std::string TimeStamp;
    LogTime::GetTimeStamp(&TimeStamp);
    std::cout<<"["<<TimeStamp<<" "<<level_info<<" "<<file<<":"<<line<<"]"<<logmsg;
    return std::cout;
}

#define LOG(lev,msg) Log(lev,__FILE__,__LINE__,msg)
