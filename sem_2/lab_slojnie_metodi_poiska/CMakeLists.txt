cmake_minimum_required(VERSION 3.10)

project(lab_slojnie_metodi_poiska LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(search_boyer_moore_horspool boyer_mur_horspula_poisk.cpp)
add_executable(search_boyer_moore boyer_mur_poisk.cpp)
add_executable(search_knuth_morris_pratt knut_morris_prat_poisk.cpp)