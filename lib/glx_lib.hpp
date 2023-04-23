#include "core/core.hpp"

#include "json/json.hpp"

using json = nlohmann::json;


char* jsonToChar(json jsonData) {
    std::string result = jsonData.dump();
    char* ch = new char[result.size() + 1];
    strcpy(ch, result.c_str());
    return ch;
}

char* stringToChar(std::string value) {
    char* ch = new char[value.size() + 1];
    strcpy(ch, value.c_str());
    return ch;
}