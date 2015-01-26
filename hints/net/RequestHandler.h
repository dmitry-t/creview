#pragma once

#include "hints/net/ServerRequest.h"
#include "hints/net/server_response.h"

namespace hints {
namespace net {

class RequestHandler
{
public:
    virtual void handleRequest(
        ServerRequest& request,
        ServerResponse& response) = 0;
};

} // namespace net
} // namespace hints
