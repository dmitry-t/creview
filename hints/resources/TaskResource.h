#pragma once

#include "hints/net/RequestHandler.h"

namespace hints {
namespace resources {

class TaskResource : public net::RequestHandler
{
public:
    typedef net::ServerRequest ServerRequest;
    typedef net::ServerResponse ServerResponse;

    TaskResource();

    virtual void handleRequest(
        ServerRequest& request,
        ServerResponse& response) override;

private:

};

} // namespace resources
} // namespace hints
