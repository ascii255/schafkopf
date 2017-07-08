cmake_minimum_required(VERSION 3.8)

project(schafkopf CXX)

file(GLOB_RECURSE SCHAFKOPF_SOURCES include/*.h)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SCHAFKOPF_SOURCES})

add_library(schafkopf INTERFACE)
target_include_directories(schafkopf INTERFACE include)
target_sources(schafkopf INTERFACE ${SCHAFKOPF_SOURCES})

add_subdirectory(test)
