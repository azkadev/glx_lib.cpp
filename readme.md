# Glx Lib Cpp

Mencoba mempermudah menggunakan bahasa cpp dengan glx lib.

## To Do

1. [ ] Add Syntax core dart
2. [ ] Docs

## Add Library

```cpp
#include "lib/glx_lib.hpp"
```

## Add On CmakeList.txt

```txt
cmake_minimum_required(VERSION 3.16)

include(CheckIncludeFileCXX)

project(glx_library VERSION 0.0.1 LANGUAGES C CXX)

---

include_directories("lib") 
 
---

```

## Quickstart

```cpp
#include "lib/glx_lib.hpp"
int main(int argc, List argv) {
    String name_program = "GLX LIB.CPP";
    /// map json
    Map jsonData = {};
    jsonData["@type"] = "ok";
    num nomor = 10;
    jsonData["number"] = nomor; 
    print(stringToChar(name_program));
    return 0;
}
```