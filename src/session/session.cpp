#include "session/session.hpp"
#include <boost/asio.hpp>
#include <string_view>

using tcp = boost::asio::ip::tcp;

Session::Session(tcp::socket socket, std::unordered_map<std::string, std::string> &server_storage) : socket_(std::move(socket)),
                                                                                                     server_storage_(server_storage) {}

void Session::parse(Request &req, std::string_view data)
{
    std::size_t pos = data.find(' ');

    req.command = data.substr(0, pos);

    if(pos == std::string_view::npos)return;

    data.remove_prefix(pos + 1);

    pos = data.find(' ');

    req.key = data.substr(0, pos);

    if (req.command == "GET" or req.command=="DEL")
        return;

    if(pos==std::string_view::npos)
    {
        req.value = {};
        return;
    }

    else
    {
        data.remove_prefix(pos + 1);
        req.value = data;
        return;
    }
}

void Session::process(Request& req)
{


    if(req.command.empty())return;


    if (req.command == "SET")
    {
        
        if(req.key.empty())
        {  
            write("No Key!\n");
            return;
        }
        if(req.value.empty())
        {
            write("No Value!\n");
            return;
        }
        server_storage_[std::string(req.key)] = std::string(req.value);
        write("Dom_Dom setted your value by this key!\n");

        return;
    }

    else if (req.command == "GET")
    {
        if(req.key.empty())
        {
            write("No Key!\n");
            return;
        }

        auto it = server_storage_.find(std::string(req.key));

        if(it == server_storage_.end())
        {
            write("No Such Key!\n");
            return;
        }

        std::string response = it->second + "\n";
        write(response);
        return;
    }

    else if (req.command == "DEL")
    {
        if(req.key.empty())
        {
            write("No Key\n");
            return;
        }

        auto it = server_storage_.find(std::string(req.key));

        if(it == server_storage_.end())
        {
            write("No Such Key!\n");
            return;
        }

        server_storage_.erase(std::string(req.key));

        write("It is deleted, indeed!\n");
        return;
    }

    else
    {
        write("Unknow Command!\n");
        return;
    }
}

void Session::read()
{
    for (;;)
    {
        boost::system::error_code ec;

        std::size_t bytes = boost::asio::read_until(socket_,
                                                    boost::asio::dynamic_buffer(buffer_),
                                                    '\n',
                                                    ec);

        if (ec)
            break;
        std::string_view temp_data{buffer_.data(), bytes};

        if (!temp_data.empty() && temp_data.back() == '\n')
        {
            temp_data.remove_suffix(1);
        }

        if (!temp_data.empty() && temp_data.back() == '\r')
        {
            temp_data.remove_suffix(1);
        }

        Request req{};

        parse(req, temp_data);
        process(req);

        buffer_.erase(0, bytes);
    }
}

void Session::write(const std::string &message)
{
    boost::asio::write(
        socket_,
        boost::asio::buffer(
            message));
}

void Session::start()
{
    read();
}
