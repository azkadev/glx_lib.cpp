#include <chrono>
#include <cmath>
#include <condition_variable>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <thread>
#include <vector>

#include "lib/glx_lib.hpp"

using namespace std;
// using json = nlohmann::json;
using namespace std;

char* jsonToChar(json jsonData);

std::string charToString(char* value);
char* stringToChar(std::string value);

json invoke(json jsonBody) {
    json jsonData;
    jsonBody["azka"] = "";

    jsonData["@type"] = "voice";

    return jsonData;
}

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

extern "C"
{

    int calculate(int num_1, int num_2) {
        return num_1 * num_2;
    }

    char* request(char* data) {
        String azka = "SLebew";

        print(stringToChar(azka));
        Map jsonBody = json::parse(data);
        json jsonResult;
        

        if (jsonBody["@type"] == "createVoice") {
            return jsonToChar(invoke(jsonBody));
        }
        if (jsonBody["@type"] == "getVersion" && jsonBody["@type"] == "getVersion" && jsonBody["@type"] == "getVersion" && jsonBody["@type"] == "getVersion" && jsonBody["@type"] == "getVersion" && jsonBody["@type"] == "getVersion" && jsonBody["@type"] == "getVersion") {
            jsonResult["@type"] = "version";
            jsonResult["message"] = "version lib v0.0.0";
            return jsonToChar(jsonResult);
        }
        jsonResult["@type"] = "error";
        jsonResult["message"] = "method_not_found";
        return jsonToChar(jsonResult);
    }
}

int main(int argc, List argv) {

    std::cout << argc << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << i << std::endl;
        std::cout << argv[i] << std::endl;
    }

    Map jsonData = {};

    jsonData["@type"] = "ok";
    num nomor = 10;
    jsonData["number"] = nomor;

    print(jsonToChar(jsonData));

    print(stringToChar("asko"));

    return 0;
}


/* code */
