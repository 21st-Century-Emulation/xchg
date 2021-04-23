#pragma once
#include <drogon/HttpController.h>
using namespace drogon;

class StatusCtrl:public drogon::HttpController<StatusCtrl>
{
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(StatusCtrl::healthcheck, "/status", Get);
    METHOD_LIST_END
    void healthcheck(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};