#include "hints/net/server_request_impl.h"
#include "contrib/poco-1.6.0/Foundation/include/Poco/URI.h"

namespace hints {
namespace net {

ServerRequestImpl::ServerRequestImpl(
        Poco::Net::HTTPServerRequest& request,
        const url::Mapper::Params& pathParams) :
    request_(request),
    pathParams_(pathParams)
{

}

const std::string* ServerRequestImpl::getCookieParam(
        const std::string& name) const
{
    if (cookies_.empty())
    {
        request_.getCookies(cookies_);
    }
    if (!cookies_.has(name))
    {
        return nullptr;
    }
    return &cookies_.get(name);
}

const std::string* ServerRequestImpl::getQueryParam(const std::string& name) const
{
    if (queryParams_.empty())
    {
        Poco::URI uri(request_.getURI());
        queryParams_ = uri.getQueryParameters();
    }
    for (auto& param : queryParams_)
    {
        if (param.first == name)
        {
            return &param.second;
        }
    }
    return nullptr;
}

const std::string* ServerRequestImpl::getPathParam(const std::string& name) const
{
    return pathParams_.count(name) ? &pathParams_.at(name) : nullptr;
}

} // namespace net
} // namespace hints
