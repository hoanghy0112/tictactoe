cmake_minimum_required(VERSION 3.10)

project(tic-tac-toe)
set(CMAKE_CXX_STANDRA 14)

add_executable(tic-tac-toe src/ai/ai.test.cpp src/ai/ai.cpp src/ai/utils.cpp)