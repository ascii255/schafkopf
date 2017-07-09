cmake_minimum_required(VERSION 3.8)

project(schafkopf CXX)

#file(GLOB_RECURSE SCHAFKOPF_SOURCES include/*.h)
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SCHAFKOPF_SOURCES})

add_library(schafkopf INTERFACE)
target_include_directories(schafkopf INTERFACE include)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/schafkopf)
target_sources(schafkopf INTERFACE
        ${INCLUDE_DIR}/engine.h
        ${INCLUDE_DIR}/player.h
        ${INCLUDE_DIR}/card.h
        ${INCLUDE_DIR}/deck.h
        ${INCLUDE_DIR}/round.h
        ${INCLUDE_DIR}/algorithm.h
        ) #${SCHAFKOPF_SOURCES})

add_subdirectory(test)
