cmake_minimum_required(VERSION 3.10)
project(lispy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory(mpc)

find_package(Edit REQUIRED)

add_executable(lispy src/parsing.cpp)

target_link_libraries(lispy
        Edit::Edit
        mpc
        )