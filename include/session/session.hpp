#include <boost/asio.hpp>
#include <memory>
#include <unordered_map>
#include <string>
#include <string_view>

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
        };

        void parse(Request& req,std::string_view data);

        void process(Request& req);

        tcp::socket socket_;
        std::string buffer_;

        std::unordered_map<std::string,std::string>& server_storage_;
};