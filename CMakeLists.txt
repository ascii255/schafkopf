cmake_minimum_required(VERSION 3.8)

project(schafkopf CXX)

#file(GLOB_RECURSE SCHAFKOPF_SOURCES include/*.h)
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SCHAFKOPF_SOURCES})

add_library(schafkopf source/engine.cpp
    include/schafkopf/engine.h
    include/schafkopf/player.h
    include/schafkopf/card.h
    include/schafkopf/deck.h
    include/schafkopf/algorithm.h
    include/schafkopf/game.h
    include/schafkopf/trick.h)
target_include_directories(schafkopf PUBLIC include)
set_target_properties(schafkopf PROPERTIES CXX_STANDARD 17)

add_subdirectory(test)
