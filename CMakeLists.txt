cmake_minimum_required(VERSION 3.0)
project(RestServerFirstTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpprestsdk REQUIRED NAMES cpprestsdk cpprest)
find_package(OpenSSL)

add_executable(cpp_rest_server main.cpp InterruptHandler.cpp)

target_include_directories(cpp_rest_server PRIVATE ${OPENSSL_INCLUDE_DIR})

target_link_libraries(cpp_rest_server PRIVATE cpprestsdk::cpprest ${OPENSSL_LIBRARIES})
