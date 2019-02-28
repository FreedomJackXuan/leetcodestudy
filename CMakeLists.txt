cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp leetcode/q1.cpp leetcode/q2.cpp leetcode/leet283.cpp leetcode/leet26.cpp leetcode/leet80.cpp leetcode/leet75.cpp leetcode/leet88.cpp leetcode/leet215.cpp leetcode/leet167.cpp leetcode/leet125.cpp leetcode/leet344.cpp leetcode/leet209.cpp leetcode/leet3.cpp leetcode/leet438.cpp leetcode/leet76.cpp leetcode/leet349.cpp)
add_executable(leetcode ${SOURCE_FILES})