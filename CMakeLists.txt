cmake_minimum_required(VERSION 3.23)
project(SoftwareEngV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoftwareEngV2 main.cpp address.h address.cpp productItem.h productItem.cpp basketItem.h basketItem.cpp user.h user.cpp shopper.h shopper.cpp admin.h admin.cpp package.h package.cpp)
