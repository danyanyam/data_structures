project(LinkedList)

# all files in directory in variable SOURCES
# aux_source_directory(. SOURCES)
# message("${SOURCES}")

add_library(LinkedList  SHARED
    LinkedList.hpp
    LinkedList.cpp
    )