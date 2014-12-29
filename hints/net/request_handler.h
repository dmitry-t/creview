#pragma once

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

namespace hints {
namespace net {

class RequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    virtual void handleRequest(
        Poco::Net::HTTPServerRequest& request,
        Poco::Net::HTTPServerResponse& response) override
    {
        if (request.getMethod() != "GET")
        {
            response.setStatus(Poco::Net::HTTPServerResponse::HTTP_METHOD_NOT_ALLOWED);
            response.send() << Poco::Net::HTTPResponse::HTTP_REASON_NOT_FOUND;
            return;
        }

        if (request.getURI() != "/") {
            response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
            response.send() << Poco::Net::HTTPResponse::HTTP_REASON_NOT_FOUND;
            return;
        }

        response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        response.send() << Poco::Net::HTTPResponse::HTTP_REASON_OK;
    }
};

} // namespace net
} // namespace hints
