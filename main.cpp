#include <boost/asio.hpp>
#include "server/server.hpp"

int main()
{
    boost::asio::io_context io;

    Server server(io,8080);

    server.start();

    return 0;
}