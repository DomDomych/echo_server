#include "session/session.hpp"
#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;

Session::Session(tcp::socket socket):socket_(std::move(socket)){}


void Session::read()
{
    socket_.async_read_some(
        boost::asio::buffer(buffer_),
        [this](
            boost::system::error_code,
            std::size_t bytes
        )
        {
            write(bytes);
        }
    );


}


void Session::write(std::size_t bytes_transfered)
{
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(buffer_.data(),bytes_transfered),

        [this](boost::system::error_code,
        std::size_t)
        {
            read();
        }
    );

}

void Session::start()
{
    read();
}

