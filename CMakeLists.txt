cmake_minimum_required(VERSION 3.20)
project(FiatShamirAuthentication)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rd-party)

set(SRC
        Parties/User.cpp
        Parties/CentralAuthority.cpp)

add_executable(FiatShamirAuthentication main.cpp ${SRC})

target_link_libraries(FiatShamirAuthentication PRIVATE BigInteger)
target_include_directories(FiatShamirAuthentication PRIVATE Parties)
