cmake_minimum_required(VERSION 3.16)

include(CheckIncludeFileCXX)

project(dart_cpp_library VERSION 0.0.1 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
message(STATUS "START COMPILE Dart CPP")
 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra -Wl,-rpath,'$ORIGIN'")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wall -Wextra")
  

find_package(PkgConfig)
# pkg_check_modules(ESPEAK_NG REQUIRED espeak-ng<2) 

set(dart_cpp_shared_dir "lib")
set(dart_cpp_exe_dir "bin")
set(prefix_shared_library "lib") 

if (ANDROID)
 set(package_shared_extension "_${ANDROID_ARCH_NAME}.so")
 set(package_exe_extension "")
 set(package_name "dart_cpp_${ANDROID_ARCH_NAME}")
elseif (WIN32)
 set(package_shared_extension ".dll")
 set(package_exe_extension ".exe") 
 set(package_name "dart_cpp")
elseif (APPLE)
 set(package_shared_extension ".dylib")
 set(package_exe_extension "") 
 set(package_name "dart_cpp")
else()
 set(package_shared_extension ".so")
 set(package_exe_extension "") 
 set(package_name "dart_cpp")
endif()


# add_subdirectory("lib/llama.cpp")
# include_directories("lib/llama.cpp")

# include_directories("/usr/include/espeak-ng")
# include_directories("Linux-x86_64/include")

add_library(dart_cpp_shared SHARED dart_cpp.cpp)
add_executable(dart_cpp_exe  dart_cpp.cpp)
 
set_target_properties(
  dart_cpp_shared PROPERTIES  
  LIBRARY_OUTPUT_DIRECTORY "${dart_cpp_shared_dir}"
  PREFIX "${prefix_shared_library}"
  OUTPUT_NAME "${package_name}"
)
  
set_target_properties(dart_cpp_exe PROPERTIES 
  RUNTIME_OUTPUT_DIRECTORY "${dart_cpp_exe_dir}"
  OUTPUT_NAME "${package_name}"
)
 
if (WIN32)
 set_target_properties(
  dart_cpp_shared PROPERTIES
  WINDOWS_EXPORT_ALL_SYMBOLS ON
)
endif (WIN32)
 

 
target_compile_definitions(
  dart_cpp_shared PUBLIC DART_SHARED_LIB
)

target_link_libraries(
  dart_cpp_shared PRIVATE 
  # onnxruntime 
  # pthread 
  # espeak-ng 
  # -static-libgcc 
  # -static-libstdc++ 
  ${CMAKE_THREAD_LIBS_INIT}
)
  
add_custom_command(
  TARGET dart_cpp_shared POST_BUILD 
  COMMAND ${CMAKE_STRIP} --strip-debug --strip-unneeded "${dart_cpp_shared_dir}/${prefix_shared_library}dart_cpp${package_shared_extension}"
)