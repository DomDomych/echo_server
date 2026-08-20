#include "protocol/command_processor.hpp"
#include <string>
#include <unordered_map>

std::string process(
    const Request& req,
    std::unordered_map<std::string,std::string>& storage
)
{

    if (req.command.empty())
        return {};

    if (req.command == "SET")
    {

        if (req.key.empty())
        {
            return "No Key!\n";
            
        }
        if (req.value.empty())
        {
            return "No Value!\n";
            
        }
        storage[std::string(req.key)] = std::string(req.value);
        return "OK!\n";
    }

    else if (req.command == "GET")
    {
        if (req.key.empty())
        {
            return "No Key!\n";
            return;
        }

        auto it = storage.find(std::string(req.key));

        if (it == storage.end())
        {
            return "No Such Key!\n";
        }

        std::string response = it->second + "\n";
        return response;
    }

    else if (req.command == "DEL")
    {
        if (req.key.empty())
        {
            return "No Key\n";
        }

        auto it = storage.find(std::string(req.key));

        if (it == storage.end())
        {
            return "No Such Key!\n";
        }

        storage.erase(std::string(req.key));

        return "OK!\n";
    }

    else
    {
        return "ERROR!\n";
    }
}