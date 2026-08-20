#pragma once

#include <boost/asio.hpp>
#include <string>
#include <unordered_map>

using tcp = boost::asio::ip::tcp;

class Session
{
  public:
    explicit Session(tcp::socket socket,
                     std::unordered_map<std::string, std::string> &server_storage);

    void start();

  private:
    void read();
    void write(const std::string &message);

    tcp::socket socket_;
    std::string buffer_;

    std::unordered_map<std::string, std::string> &server_storage_;
};