cmake_minimum_required(VERSION 3.14)
project(sort-algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sort-algorithms main.cpp bubble.h insert.h merge.h mocker.cpp mocker.h quick.h select.h shell.h sort.h tester.h tester.cpp)
