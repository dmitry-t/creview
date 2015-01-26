#pragma once

#include "Poco/Net/HTTPServerRequest.h"

#include <string>

namespace hints {
namespace net {

class ServerRequest {
public:
    virtual const std::string* getCookieParam(const std::string& name) const = 0;
    virtual const std::string* getQueryParam(const std::string& name) const = 0;
    virtual const std::string* getPathParam(const std::string& name) const = 0;
};

} // namespace net
} // namespace hints
