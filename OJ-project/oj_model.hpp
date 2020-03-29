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
    private:
        std::unordered_map<std::string,Question> _model_map;
};


