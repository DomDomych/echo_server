#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;

class Session
{
    public:
        explicit Session(tcp::socket& socket);

        void start();

    private:
        void read();
        tcp::socket socket_;
};