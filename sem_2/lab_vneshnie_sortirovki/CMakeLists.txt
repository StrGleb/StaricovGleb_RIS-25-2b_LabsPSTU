cmake_minimum_required(VERSION 3.10)

project(lab_vneshnie_sortirovki LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sort_balanced_two_way sort_balanse_two_putey.cpp)
add_executable(sort_natural_merge sort_estestv_sliyanie.cpp)
add_executable(sort_polyphase sort_mnogofaz.cpp)