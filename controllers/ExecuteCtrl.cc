#include "ExecuteCtrl.h"

void ExecuteCtrl::execute(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json = req.get()->getJsonObject();

    auto cycles = (*json)["state"]["cycles"].asUInt64();
    (*json)["state"]["cycles"] = cycles + 5;
    uint8_t h = (*json)["state"]["h"].asUInt();
    uint8_t l = (*json)["state"]["l"].asUInt();
    (*json)["state"]["h"] = (*json)["state"]["d"].asUInt();
    (*json)["state"]["l"] = (*json)["state"]["e"].asUInt();
    (*json)["state"]["d"] = h;
    (*json)["state"]["e"] = l;

    auto resp = HttpResponse::newHttpJsonResponse(*json);
    callback(resp);
}