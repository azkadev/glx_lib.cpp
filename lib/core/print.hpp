#include <iostream>
#include <string>
#include <typeinfo>

std::string charToString(char* value) {
    std::string result(value);
    return result;
}

template <typename T>
void print(const T& value) {
    if (typeid(value) == typeid(char*)) {
        std::cout << typeid(value).name() << std::endl;
    } else {
        std::cout << value << std::endl;
    }
}
