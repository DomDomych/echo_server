#include "session/session.hpp"
#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;

Session::Session(tcp::socket socket):socket_(std::move(socket)){}


void Session::read()
{
    for(;;)
    {
        boost::system::error_code ec;

        std::size_t bytes = socket_.read_some(
            boost::asio::buffer(buffer_),
            ec
        );

        if(ec)break;

        write(bytes);
    }



}


void Session::write(std::size_t bytes_transfered)
{
    boost::asio::write(
        socket_,
        boost::asio::buffer(
            buffer_.data(),
            bytes_transfered
        )
    );

}

void Session::start()
{
    read();
}

