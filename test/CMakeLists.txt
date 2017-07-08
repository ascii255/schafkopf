cmake_minimum_required(VERSION 3.8)

file(GLOB_RECURSE TEST_SOURCES source/*.cpp)

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest EXCLUDE_FROM_ALL)
enable_testing()

add_executable(runUnitTests ${TEST_SOURCES})
target_link_libraries(runUnitTests schafkopf gtest_main)
set_target_properties(runUnitTests PROPERTIES CXX_STANDARD 17)
