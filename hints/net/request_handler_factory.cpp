#include "hints/net/request_handler_factory.h"
#include "hints/net/request_handler.h"

namespace hints {
namespace net {

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request
    )
{
    return new RequestHandler;
}

} // namespace net
} // namespace hints
