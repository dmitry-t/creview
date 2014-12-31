#pragma once

#include "hints/net/request_handler.h"
#include "hints/net/request_handler_factory.h"
#include "hints/net/url/mapper.h"

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"

namespace hints {
namespace net {

class RequestHandlerRegistry : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    RequestHandlerRegistry& addFactory(
            std::string parametrizedURL,
            RequestHandlerFactory handlerFactory);

    template<class T>
    RequestHandlerRegistry& addHandler()
    {
        return addFactory(T::path(), [] { return new T; });
    }

    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(
            const Poco::Net::HTTPServerRequest& request) override;

private:
    url::Mapper mapper_;
    std::vector<RequestHandlerFactory> factories_;
};

} // namespace net
} // namespace hints
