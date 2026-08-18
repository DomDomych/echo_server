#include <boost/asio.hpp>
#include <array>
#include <memory>
#include <unordered_map>
#include <string>

using tcp = boost::asio::ip::tcp;

class Session
{
    public:
        explicit Session(tcp::socket socket,std::unordered_map<std::string,std::string>& server_storage);

        void start();

    private:
        void read();
        void write(const std::string& message);

        struct Request
        {
            std::string_view command{};
            std::string_view key{};
            std::string_view value{};
        }req;

        void parse(Request& req,std::string_view data);


        tcp::socket socket_;
        std::array<char,1024> buffer_;

        std::unordered_map<std::string,std::string> server_storage_;
};