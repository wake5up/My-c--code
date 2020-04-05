#include <stdio.h>                                      
#include <string>            
#include <string.h>                                              

#include "httplib.h"
#include "oj_model.hpp"                                                           
#include "oj_view.hpp" 
#include "oj_log.hpp"                                 
#include "compile.hpp"
int main()
{
    using namespace httplib;
    Server svr;
    OjModel ojmodel;
    svr.Get("all_questions",[&ojmodel](const Request& req,Response& resp){
            std::vector<Question> ques;
            ojmodel.GetAllQuestions(&ques);
            std::string html;
            OjView::ExpandAllQuestionshtml(&html,ques);
            resp.set_content(html,"test/html;charset=UTF-8");
            });

    svr.Get(R"(question/(\d+))",[&ojmodel](const Request& req,Response& resp){
            std::string desc;
            std::string header;
            //利用正则表达式获取id
            LOG(INFO,"req.matches")<<req.matches[0]<<":"<<req.matches[1]<<std::endl;
            //在题目地址的路径下去加载单个题目的描述信息
            struct Question ques;
            ojmodel.GetOneQuestion(req.matches[1].str(),&desc,&header,&ques);
            //进行组织，返回给客户端
            std::string html;
            OjView::ExpandOneQuestion(ques,desc,header,&html);
            resp.set_content(html,"text/html;charset=UTF-8");
            });

    svr.Post(R"(/question/(\d+))",[&ojmodel](const Request& req,Response& resp){
            //从正文当中提取用户提交的内容，主要是提取code字段所对应的内容，即req.body
            std::unordered_map<std::string,std::string> pram;
            UrlUtil::PraseBody(req.body,&pram);
            std::string code;
            ojmodel.SplicingCode(pram["code"], req.matches[1].str(), &code);
            Json::Value req_json;
            req_json["code"] = code;
            Json::Value Resp_json;
            Compiler::CompilerAndRun(req_json, &Resp_json);
            //构造响应
            const std::string errorno = Resp_json["errorno"].asString();
            const std::string reason = Resp_json["reason"].asString();
            const std::string stdout_reason = Resp_json["stdout"].asString();
            std::string html;
            OjView::ExpandReason(errorno, reason, stdout_reason, &html);
            resp.set_content(html,"text/html; charset=UTF-8");
            });

    LOG(INFO,"listen in 0.0.0.0:16666")<<std::endl;
    LOG(INFO,"Server ready")<<std::endl;
    svr.listen("0.0.0.9",16666);
    return 0;
}
