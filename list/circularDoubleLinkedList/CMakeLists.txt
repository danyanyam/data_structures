project(CircularList)

# all files in directory in variable SOURCES
# aux_source_directory(. SOURCES)
# message("${SOURCES}")

add_library(CircularList  SHARED
    circularDoubleLinkedList.hpp
    circularDoubleLinkedList.cpp
    )