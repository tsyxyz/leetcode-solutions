cmake_minimum_required(VERSION 3.10.2)

project(leetcode-solutions)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB SOURCES *.cpp)

set(LEETCODE_SOLUTIONS_BIN solutions)
add_executable(${LEETCODE_SOLUTIONS_BIN} ${SOURCES} main.cpp)
target_link_libraries(${LEETCODE_SOLUTIONS_BIN} GTest::GTest)