#include "creview/net/request_handler_factory.h"
#include "creview/net/request_handler.h"

namespace creview {
namespace net {

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request
    )
{
    return new RequestHandler;
}

} // namespace net
} // namespace creview
