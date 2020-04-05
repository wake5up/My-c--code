#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <algorithm>
#include "tools.hpp"

typedef struct Question
{
    std::string _id;
    std::string _name;
    std::string _path;
    std::string _star;
}QUES;

class OjModel
{
    public:
        OjModel()
        {
            LoadQuestions("./config_oj.cfg");
        }

        bool GetAllQuestions(std::vector<Question>* ques)
        {
            for(auto& e:_model_map)
            {
                ques->push_back(e.second);
            }
            std::sort(ques->begin(),ques->end(),[](const Question& left,const Question& right){
                    return std::atoi(left._id.c_str())<std::atoi(right._id.c_str());
                    });
        }

        bool GetOneQuestion(const std::string& id,std::string* desc,std::string* header,Question* ques)
        {
            auto iter=_model_map.find(id);
            if(iter==_model_map.end())
            {
                LOG(ERROR,"Not Fount Question id is")<<id<<std::endl;
                return false;
            }
            *ques=iter->second;

            int ret=FileOper::ReadDataFromFile(DescPath(iter->second._path),desc);
            if(ret==-1)
            {
                LOG(ERROR,"Read desc failed");
                return false;
            }

            ret=FileOper::ReadDataFromFile(HeaderPath(iter->second._path),header);
            if(ret==-1)
            {
                LOG(ERROR,"Read desc failed")<<std::endl;
                return false;
            }
            return true;
        }

        //合并用户代码和测试代码
        bool SplicingCode(std::string user_code,const std::string& ques_id,std::string* code)
        {
            auto it=_model_map.find(ques_id);
            if(it==_model_map.end())
            {
                LOG(ERROR,"can not found question id is")<<ques_id<<std::endl;
                return false;
            }
            std::string tail_code;
            int ret=FileOper::ReadDataFromFile(TailPath(it->second._path),&tail_code);
            if(ret==-1)
            {
                LOG(ERROR,"Open tail.cpp failed");
                return false;
            }
            *code=user_code+tail_code;
            return true;
        }

    private:
        bool LoadQuestions(const std::string& configfile_path)
        {
            std::ifstream file(configfile_path.c_str());
            if(!file.is_open())
            {
                return false;
            }
            std::string line;
            while(std::getline(file,line))
            {
                std::vector<std::string> vec;
                StringTools::Split(line," ",&vec);
                if(vec.size()!=4)
                {
                    continue;
                }
                Question ques;
                ques._id=vec[0];
                ques._name=vec[1];
                ques._path=vec[2];
                ques._star=vec[3];
                _model_map[ques._id]=ques;
            }   
            file.close();
            return true;
        }

        std::string DescPath(const std::string& ques_path)
        {
            return ques_path + "desc.txt";

        }
        std::string HeaderPath(const std::string& ques_path)
        {
            return ques_path + "header.cpp";

        }
        std::string TailPath(const std::string& ques_path)
        {
            return ques_path + "tail.cpp";

        }
    private:
        std::unordered_map<std::string,Question> _model_map;
};


