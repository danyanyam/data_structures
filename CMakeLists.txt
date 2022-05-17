cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++20")

project(main)


add_executable(
    main
    main.cpp # add execs here
)
