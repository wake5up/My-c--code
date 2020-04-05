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
    //httplib的时候，需要使用httplib提供的命名空间
    using namespace httplib;
    Server svr;
    OjModel ojmodel;
    svr.Get("/all_questions", [&ojmodel](const Request& req, Response& resp){
            std::vector<Question> ques;
            ojmodel.GetAllQuestions(&ques);
            std::string html;
            OjView::ExpandAllQuestionshtml(&html, ques);
            //LOG(INFO, html);
            resp.set_content(html,"text/html; charset=UTF-8");
            });
    //正则表达式
    //源码转义：特殊字符就按照特殊字符字面源码来编译
    //      R"(str)"
    svr.Get(R"(/question/(\d+))", [&ojmodel](const Request& req, Response& resp){
            // question/1
            std::string desc;//题目信息
            std::string header;
            //从Get方法中获取id，即matches[1]
            LOG(INFO, "req.matches") << req.matches[0] << ":" << req.matches[1] << std::endl;
            // 在题目地址的路径下去加载单个题目的描述信息
            struct Question ques;
            ojmodel.GetOneQuestion(req.matches[1].str(), &desc, &header, &ques);
            // 进行组织，返回给浏览器
            std::string html;
            OjView::ExpandOneQuestion(ques, desc, header, &html);
            resp.set_content(html,"text/html; charset=UTF-8");
            });
    svr.Post(R"(/question/(\d+))", [&ojmodel](const Request& req, Response& resp){
            //key:value
            //  从正文(即req.body)当中提取出来提交的内容。主要是提取code字段所对应的内容
            //  提交的内容当中有url编码--》提交内容进行 解码
            //  提取完成后的数据放到 unordered_map<std::string, std::string>
            std::unordered_map<std::string, std::string> pram;
            UrlUtil::PraseBody(req.body, &pram);
            //编译&运行
            //需要给提交的代码增加头文件，测试用例，main函数
            std::string code;
            ojmodel.SplicingCode(pram["code"], req.matches[1].str(), &code); 
            //LOG(INFO, "code ") << code << std::endl;
            Json::Value req_json;
            req_json["code"] = code;
            Json::Value Resp_json;
            Compiler::CompileAndRun(req_json, &Resp_json);
            //构造响应
            const std::string errorno = Resp_json["errorno"].asString();
            const std::string reason = Resp_json["reason"].asString();
            const std::string stdout_reason = Resp_json["stdout"].asString();
            std::string html;
            OjView::ExpandReason(errorno, reason, stdout_reason, &html);
            resp.set_content(html,"text/html; charset=UTF-8");
            });
    LOG(INFO, "listen in 0.0.0.0:16666") << std::endl;
    LOG(INFO, "Server ready") << std::endl;
    //listen 会阻塞监听
    svr.listen("0.0.0.0", 16666);
    return 0;
}
