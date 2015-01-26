#pragma once

#include "hints/net/RequestHandler.h"
#include "hints/net/request_handler_factory.h"
#include "hints/net/url/mapper.h"

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace hints {
namespace net {

class RequestHandlerRegistry : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    RequestHandlerRegistry& addFactory(
            const std::string& method,
            const std::string& parametrizedURL,
            RequestHandlerFactory handlerFactory);

    // Adds a factory for the handler of type T. The type T must implement
    // the RequestHandler interface and have static method() and path() methods.)
    template<class T>
    RequestHandlerRegistry& addHandler()
    {
        return addFactory(T::method(), T::path(), [] { return new T; });
    }

    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(
            const Poco::Net::HTTPServerRequest& request) override;

private:
    struct MethodHandler
    {
        url::Mapper mapper_;
        std::vector<RequestHandlerFactory> factories_;
    };
    std::unordered_map<std::string, MethodHandler> handlers_;
};

} // namespace net
} // namespace hints
