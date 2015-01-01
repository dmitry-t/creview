#include "hints/net/server_response_impl.h"

#include "Poco/Net/HTTPCookie.h"

namespace hints {
namespace net {

ServerResponseImpl::ServerResponseImpl(Poco::Net::HTTPServerResponse& response) :
    response_(response)
{
}

ServerResponse& ServerResponseImpl::setStatus(
        HTTPStatus statusCode,
        const std::string& reasonPhrase)
{
    response_.setStatusAndReason(statusCode, reasonPhrase);
    return *this;
}

ServerResponse& ServerResponseImpl::setContentType(const std::string& value)
{
    response_.setContentType(value);
    return *this;
}

ServerResponse& ServerResponseImpl::addCookie(
        const std::string& name,
        const std::string& value,
        Timespan maxAge)
{
    Poco::Net::HTTPCookie cookie(name, value);
    cookie.setMaxAge(maxAge.seconds());
    response_.addCookie(std::move(cookie));
    return *this;
}

ServerResponse& ServerResponseImpl::body(const std::string& body)
{
    body_ += body;
    return *this;
}

ServerResponse& ServerResponseImpl::sendWithEOM()
{
    response_.send() << body_;
    return *this;
}

} // namespace net
} // namespace hints
