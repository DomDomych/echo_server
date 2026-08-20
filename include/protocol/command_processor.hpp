#pragma once

#include "request.hpp"
#include <string>
#include <unordered_map>

std::string process(const Request &req, std::unordered_map<std::string, std::string> &storage);