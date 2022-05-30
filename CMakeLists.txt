cmake_minimum_required(VERSION 3.20)
project(FiatShamirAuthentication)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(3rd-party)

add_executable(FiatShamirAuthentication main.cpp)

target_link_libraries(FiatShamirAuthentication PRIVATE Dodecahedron_Bigint)
