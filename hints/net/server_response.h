#pragma once

#include "hints/net/HTTPStatus.h"
#include "hints/timespan.h"

#include <string>

namespace hints {
namespace net {

class ServerResponse
{
public:
    virtual ServerResponse& setStatus(
            HTTPStatus statusCode,
            const std::string& reasonPhrase) = 0;
    virtual ServerResponse& setContentType(const std::string& value) = 0;
    virtual ServerResponse& addCookie(
            const std::string& name,
            const std::string& value,
            Timespan maxAge) = 0;
    virtual ServerResponse& body(const std::string& body) = 0;
    virtual ServerResponse& sendWithEOM() = 0;
};

} // namespace net
} // namespace hints
