#pragma once
#include <drogon/HttpController.h>
using namespace drogon;

class ExecuteCtrl:public drogon::HttpController<ExecuteCtrl>
{
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(ExecuteCtrl::execute, "/api/v1/execute", Post);
    METHOD_LIST_END
    void execute(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};