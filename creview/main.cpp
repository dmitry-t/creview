#include "creview/net/request_handler_factory.h"

#include "Poco/Net/HTTPServer.h"
#include "Poco/Util/ServerApplication.h"

#include <iostream>
#include <vector>
#include <string>

using Poco::Util::ServerApplication;

namespace creview {

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
        Poco::Net::HTTPServer server(new net::RequestHandlerFactory, port);
        server.start();
        waitForTerminationRequest();
        server.stop();
        return EXIT_OK;
    }
};

} // namespace creview

int main(int argc, char* argv[])
{
    creview::ServerApp app;
    return app.run(argc, argv);
}
