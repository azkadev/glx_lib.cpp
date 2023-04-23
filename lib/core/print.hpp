#include <iostream>

 
std::string charToString(char* value) {
    std::string result(value);
    return result;
}

template<typename T>
void print(const T&  value) { 
    std::cout << value << std::endl;
}