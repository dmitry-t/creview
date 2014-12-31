#include "hints/net/request_handler_registry.h"
#include "hints/net/request_handler.h"

#include "Poco/Net/HTTPServer.h"
#include "Poco/Util/ServerApplication.h"

#include <iostream>
#include <vector>
#include <string>

using Poco::Util::ServerApplication;

namespace hints {

class GetTestHandler : public net::RequestHandler
{
public:
    static const char* method()
    {
        return "GET";
    }

    static const char* path()
    {
        return "/test/{id}";
    }

    virtual void handleRequest(
            net::ServerRequest& request,
            net::ServerResponse& response) override
    {
        response.setStatus(net::HTTPStatus::HTTP_OK, "OK")
                .setContentType("text/json")
                .body("{\"id\": \"" + *request.getPathParam("id") + "\"\n")
                .sendWithEOM();
    }
};

class PostTestHandler : public GetTestHandler
{
public:
    static const char* method()
    {
        return "POST";
    }

    virtual void handleRequest(
            net::ServerRequest& request,
            net::ServerResponse& response) override
    {
        response.setStatus(net::HTTPStatus::HTTP_OK, "OK")
                .setContentType("text/json")
                .body(std::string("{\"status\": \"") +
                        (request.getQueryParam("p") ? "found" : "not found") +
                        "\"}\n")
                .sendWithEOM();
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
        auto pRegistry = new net::RequestHandlerRegistry;
        pRegistry->addHandler<GetTestHandler>()
                .addHandler<PostTestHandler>();
        Poco::Net::HTTPServer server(pRegistry, port);
        server.start();
        waitForTerminationRequest();
        server.stop();
        return EXIT_OK;
    }
};

} // namespace hints

int main(int argc, char* argv[])
{
    hints::ServerApp app;
    return app.run(argc, argv);
}
