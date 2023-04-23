#include <iostream>


std::string charToString(char* value) {
    std::string result(value);
    return result;
}

void print(char* value) {
    std::cout << charToString(value) << std::endl;
}