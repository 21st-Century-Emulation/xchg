#include "StatusCtrl.h"

void StatusCtrl::healthcheck(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("Healthy");
    callback(resp);
}