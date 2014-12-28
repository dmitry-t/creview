#include "Poco/Logger.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Util/ServerApplication.h"

#include <iostream>
#include <vector>
#include <string>

using Poco::Net::HTTPResponse;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::ServerApplication;

namespace creview {

class RequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    virtual void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response
        ) override
    {
        if (request.getMethod() != "GET")
        {
            response.setStatus(HTTPServerResponse::HTTP_METHOD_NOT_ALLOWED);
            response.send() << HTTPResponse::HTTP_REASON_NOT_FOUND;
            return;
        }

        if (request.getURI() != "/") {
            response.setStatus(HTTPResponse::HTTP_NOT_FOUND);
            response.send() << HTTPResponse::HTTP_REASON_NOT_FOUND;
            return;
        }

        response.setStatus(HTTPResponse::HTTP_OK);
        response.send() << HTTPResponse::HTTP_REASON_OK;
    }
};

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    virtual RequestHandler* createRequestHandler(
        const HTTPServerRequest& request
        ) override
    {
        return new RequestHandler;
    }

};

class ServerApp : public ServerApplication
{
protected:
    virtual void initialize(Application& self) override
    {
        std::cout << "Starting" << std::endl;
        loadConfiguration();
        ServerApplication::initialize(self);
    }

    virtual void uninitialize()
    {
        std::cout << "Stopping" << std::endl;
        ServerApplication::uninitialize();
    }

    virtual int main(const std::vector<std::string>& args) override
    {
	uint16_t port = config().getInt("server.port");
        std::cout << "Listening port " << port << std::endl;
        HTTPServer server(new RequestHandlerFactory, port);
        server.start();
        waitForTerminationRequest();
        server.stop();
        return EXIT_OK;
    }
};

}

int main(int argc, char* argv[])
{
    creview::ServerApp app;
    return app.run(argc, argv);
}
