#pragma once

#include "hints/net/server_request.h"
#include "hints/net/url/mapper.h"

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/URI.h"

namespace hints {
namespace net {

class ServerRequestImpl : public ServerRequest
{
public:
    explicit ServerRequestImpl(
            Poco::Net::HTTPServerRequest& request,
            const url::Mapper::Params& pathParams);

    virtual const std::string* getCookieParam(
            const std::string& name) const override;
    virtual const std::string* getQueryParam(
            const std::string& name) const override;
    virtual const std::string* getPathParam(
            const std::string& name) const override;

private:
    Poco::Net::HTTPServerRequest& request_;
    const url::Mapper::Params& pathParams_;
    mutable Poco::URI::QueryParameters queryParams_;
    mutable Poco::Net::NameValueCollection cookies_;
};

} // namespace net
} // namespace hints
