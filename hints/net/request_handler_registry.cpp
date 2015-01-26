#include <memory>

#include "hints/net/request_handler_registry.h"
#include "hints/net/RequestHandler.h"
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
        const std::string& method,
        const std::string& parametrizedURL,
        RequestHandlerFactory handlerFactory)
{
    if (!handlers_.count(method))
    {
        handlers_.emplace(method, MethodHandler());
    }
    auto& handler = handlers_.at(method);
    handler.mapper_.put(parametrizedURL, handler.factories_.size());
    handler.factories_.push_back(handlerFactory);
    return *this;
}

Poco::Net::HTTPRequestHandler* RequestHandlerRegistry::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request)
{
    if (!handlers_.count(request.getMethod()))
    {
        return nullptr;
    }
    auto& handler = handlers_.at(request.getMethod());
    url::Mapper::Params pathParams;
    size_t handlerId;
    if (handler.mapper_.get(request.getURI(), pathParams, handlerId))
    {
        return new RequestHandlerWrapper(
                handler.factories_[handlerId](),
                std::move(pathParams));
    }
    return nullptr;
}

} // namespace net
} // namespace hints
