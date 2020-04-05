#pragma once
#include <ctemplate/template.h>
#include <string>
#include <vector>
#include "oj_model.hpp"

//渲染类
class OjView
{
    public:
        static void ExpandAllQuestionshtml(std::string* html,std::vector<Question>& ques)
        {
            //获取数据字典--将拿到的试题数据按照一定顺序保存到内存当中
            ctemplate::TemplateDictionary dict("all_questions");
            for(const auto& e:ques)
            {
                //子字典
                ctemplate::TemplateDictionary* section_dict=dict.AddSectionDictionary("question");
                section_dict->SetValue("id",e._id);
                section_dict->SetValue("id",e._id);
                section_dict->SetValue("name",e._name);
                section_dict->SetValue("star",e._star);
            }
            //获取模板类指针，加载预定义的HTML页面到内存中
            ctemplate::Template* tl=ctemplate::Template::GetTemplate("./template/all_questions.html",ctemplate::DO_NOT_STRIP);
            //渲染，拿着模板类的指针，将数据字典当中的数据更新到HTML页面的内存中
            tl->Expand(html,&dict);
        }

        static void ExpandOneQuestion(const Question& ques, std::string& desc, 
                std::string& header, std::string* html)
        {
            ctemplate::TemplateDictionary dict("question");
            dict.SetValue("id", ques.id_);
            dict.SetValue("name", ques.name_);
            dict.SetValue("star", ques.star_);
            dict.SetValue("desc", desc);
            dict.SetValue("header", header);

            ctemplate::Template* tpl = ctemplate::Template::GetTemplate("./template/question.html", ctemplate::DO_NOT_STRIP);
            tpl->Expand(html, &dict);

        }

        static void ExpandReason(const std::string& errorno,const std::string& reason,const std::string& stdout_reason,std::string* html)
        {
            ctemplate::TemplateDictionary dict("reason");
            dict.SetValue("errorno",errorno);
            dict.SetValue("reason",reason);
            dict.SetValue("stdout",stdout_reason);
            ctemplate::Template* tl=ctemplate::Template::GetTemplate("./template/reason.html",ctemplate::DO_NOT_STRIP);
            tp->Expand(html,&dict);
        }
};
