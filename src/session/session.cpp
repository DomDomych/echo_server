#include "session/session.hpp"
#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;

Session::Session(tcp::socket socket,std::unordered_map<std::string,std::string>& server_storage):socket_(std::move(socket)),
    server_storage_(server_storage){}

void Session::parse(Request& req,std::string_view data)
{
    std::size_t pos = data.find(' ');

    req.command = data.substr(0,pos);

    data.remove_prefix(pos+1);

    pos = data.find(' ');

    req.key = data.substr(0,pos);

    if(req.command == "GET")return;

    else
    {
        data.remove_prefix(pos+1);
        req.value = data;
        return;
    }
}

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
        std::string_view temp_data{buffer_.data(),bytes};

        if(!temp_data.empty() && temp_data.back()=='\n' ||
           !temp_data.empty() && temp_data.back()=='\r')
        {
            temp_data.remove_suffix(1);
        }
        parse(req,temp_data);

        if(req.command=="SET")
        {

           server_storage_[std::string(req.key)]=std::string(req.value); 
           write("Dom_Dom setted your value by this key!\n");   
        }

        else if(req.command == "GET")
        {
            std::string response = server_storage_[std::string(req.key)]+"\n";
            write(response);
        }

        
    }



}


void Session::write(const std::string& message)
{
    boost::asio::write(
        socket_,
        boost::asio::buffer(
            message
        )
    );

}

void Session::start()
{
    read();
}

