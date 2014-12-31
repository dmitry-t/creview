#include <memory>

#include "hints/net/request_handler_registry.h"
#include "hints/net/request_handler.h"
#include "hints/net/server_request_impl.h"
#include "hints/net/server_response_impl.h"
#include "url/mapper.h"

namespace hints {
namespace net {

class RequestHandlerWrapper : public Poco::Net::HTTPRequestHandler
{
public:
    RequestHandlerWrapper(
            RequestHandler* pHandler,
            url::Mapper::Params pathParams) :
        handler_(pHandler),
        pathParams_(pathParams)
    {
    }

    virtual void handleRequest(
            Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override
    {
        ServerRequestImpl requestWrapper(request, pathParams_);
        ServerResponseImpl responseWrapper(response);
        handler_->handleRequest(requestWrapper, responseWrapper);
    }

private:
    std::unique_ptr<RequestHandler> handler_;
    url::Mapper::Params pathParams_;
};

RequestHandlerRegistry& RequestHandlerRegistry::addFactory(
        std::string parametrizedURL,
        RequestHandlerFactory handlerFactory)
{
    mapper_.put(parametrizedURL, factories_.size());
    factories_.push_back(handlerFactory);
}

Poco::Net::HTTPRequestHandler* RequestHandlerRegistry::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request)
{
    url::Mapper::Params pathParams;
    size_t handlerId;
    if (mapper_.get(request.getURI(), pathParams, handlerId))
    {
        return new RequestHandlerWrapper(
                factories_[handlerId](),
                std::move(pathParams));
    }
    return nullptr;
}

} // namespace net
} // namespace hints
