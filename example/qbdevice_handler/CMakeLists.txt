cmake_minimum_required(VERSION 2.8.3)
project(qbdevice_handler)

add_definitions(-std=c++11)

add_executable(qbdevice_handler qbdevice_handler.cpp ../../qbAPI/src/qbmove_communications.cpp)