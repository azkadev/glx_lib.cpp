#include "lib/glx_lib.hpp"

int main(int argc, List argv) { 

    String name_program = "GLX LIB.CPP"; 
    /// map json
    Map jsonData = {};
    jsonData["@type"] = "ok";
    num nomor = 10;
    jsonData["number"] = nomor;
    print(jsonData["number"]);
    return 0;
}