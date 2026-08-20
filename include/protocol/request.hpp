#pragma once

#include <string_view>

struct Request
{
    std::string_view command{};
    std::string_view key{};
    std::string_view value{};
};