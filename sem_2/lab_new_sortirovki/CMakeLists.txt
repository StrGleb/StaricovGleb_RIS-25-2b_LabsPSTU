cmake_minimum_required(VERSION 3.10)

project(lab_new_sortirovki LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sort_fast_hoare fast_sort_hoara.cpp)
add_executable(sort_quick_lomuto quick_sort_lomuto.cpp)
add_executable(sort_block sort_blochnaya.cpp)
add_executable(sort_counting sort_podschetom.cpp)
add_executable(sort_shell sort_shell.cpp)
add_executable(sort_merge sort_sliyaniem.cpp)