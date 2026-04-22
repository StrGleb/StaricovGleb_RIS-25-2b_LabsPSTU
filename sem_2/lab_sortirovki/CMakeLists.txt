cmake_minimum_required(VERSION 3.10)

project(lab_sortirovki LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sort_bubble sort_bubble.cpp)
add_executable(sort_selection sort_vibora.cpp)
add_executable(sort_insertion sort_vstavkami.cpp)