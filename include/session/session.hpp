#include <boost/asio.hpp>
#include <array>
#include <memory>

using tcp = boost::asio::ip::tcp;

class Session
{
    public:
        explicit Session(tcp::socket socket);

        void start();

    private:
        void read();
        void write(std::size_t bytes_transfered);

        tcp::socket socket_;
        std::array<char,1024> buffer_;
};