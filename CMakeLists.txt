cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++20")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")

project(data_structures LANGUAGES CXX)

# create executable from list of source files

find_package(LinkedList REQUIRED)
include_directories("${LinkedList_INCLUDE_DIRS}")
add_subdirectory("list/linkedList")

find_package(CircularList REQUIRED)
include_directories("${CircularList_INCLUDE_DIRS}")  # headers path
add_subdirectory("list/circularDoubleLinkedList")

add_executable(
    main
    main.cpp
)
target_link_libraries(
    main
	LinkedList
    CircularList
    )



