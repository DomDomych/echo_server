#include <boost/asio.hpp>
#include <iostream>

using tcp = boost::asio::ip::tcp;

int main()
{
    boost::asio::io_context io;

    tcp::socket socket(io);

    tcp::endpoint endpoint{boost::asio::ip::make_address("127.0.0.1"), 8080};

    boost::system::error_code ec;

    socket.connect(endpoint,ec);

    if(ec)
    {
        std::cerr<<"Connection failed: "<<ec.message()<<'\n';
        return 1;
    }

    std::cout << "Connected\n";

    std::string request;

    for(;;)
    {

        std::cout<<"> ";

        if(!std::getline(std::cin,request))break;


        if (request == "exit")
            break;

        request += '\n';

        boost::asio::write(
            socket,
            boost::asio::buffer(request)
        );

        std::string response;

        boost::asio::read_until(socket,
        boost::asio::dynamic_buffer(response),
        '\n');

        std::cout<<response;
    }
}