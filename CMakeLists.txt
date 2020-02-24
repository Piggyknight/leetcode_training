cmake_minimum_required(VERSION 3.8)
set(CMAKE_C_COMILER "gcc")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_COMPILER "g++")

PROJECT(leetcode_demo)

file(GLOB_RECURSE leetcode_demo_src
	"./leet_code_training.cpp"
	"./leet_code_training/src/*.cpp"
	"./leet_code_training/src/*.h"
)

ADD_EXECUTABLE(leetcode_demo ${leetcode_demo_src})
