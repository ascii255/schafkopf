cmake_minimum_required(VERSION 3.8)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Catch/include)
file(GLOB_RECURSE CATCH_SOURCES ${CATCH_INCLUDE_DIR}/*.h*)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CATCH_SOURCES})

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE ${CATCH_INCLUDE_DIR})
target_sources(catch INTERFACE ${CATCH_SOURCES})

add_executable(runUnitTests source/game_test.cpp)
target_link_libraries(runUnitTests schafkopf catch)
set_target_properties(runUnitTests PROPERTIES CXX_STANDARD 17)
