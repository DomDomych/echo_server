#include "protocol/parser.hpp"

void parse(Request& req,std::string_view data)
{
    std::size_t pos = data.find(' ');

    req.command = data.substr(0, pos);

    if (pos == std::string_view::npos)
        return;

    data.remove_prefix(pos + 1);

    pos = data.find(' ');

    req.key = data.substr(0, pos);

    if (req.command == "GET" or req.command == "DEL")
        return;

    if (pos == std::string_view::npos)
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
