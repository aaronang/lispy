cmake_minimum_required(VERSION 3.10)
project(mpc VERSION 0.9.0)

add_library(mpc src/mpc.c)

target_include_directories(mpc
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )