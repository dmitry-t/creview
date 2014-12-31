#pragma once

#include "hints/net/server_response.h"

#include "Poco/Net/HTTPServerResponse.h"

namespace hints {
namespace net {

class ServerResponseImpl : public ServerResponse
{
public:
    explicit ServerResponseImpl(Poco::Net::HTTPServerResponse& response);

    virtual ServerResponse& setStatus(
            HTTPStatus statusCode,
            const std::string& reasonPhrase) override;
    virtual ServerResponse& setContentType(const std::string& value) override;
    virtual ServerResponse& addCookie(
            const std::string& name,
            const std::string& value,
            Timespan maxAge) override;
    virtual ServerResponse& body(const std::string& body) override;
    virtual ServerResponse& sendWithEOM() override;

private:
    Poco::Net::HTTPServerResponse& response_;
    std::string body_;
};

} // namespace net
} // namespace hints
