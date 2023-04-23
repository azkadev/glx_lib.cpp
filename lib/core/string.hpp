#include <iostream>
#include <string>
#include <algorithm>

namespace std {
    std::string toLowerCase(const std::string& str) {
        std::string result(str);
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
}

typedef std::__cxx11::basic_string<char> String;