#include "server/server.hpp"
#include <boost/asio.hpp>


using  tcp = boost::asio::ip::tcp;

Server::Server(boost::asio::io_context& io,
               unsigned short port):
               acceptor_(io,tcp::endpoint(tcp::v4(),port)){}

void Server::accept_client()
{
    tcp::socket socket = acceptor_.accept();

}

void Server::start()
{
    accept_client();
}



