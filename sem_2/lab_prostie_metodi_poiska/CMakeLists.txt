cmake_minimum_required(VERSION 3.10)

project(lab_prostie_metodi_poiska LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(search_binary bin_poisk.cpp)
add_executable(search_interp interp_poisk.cpp)
add_executable(search_linear lin_poisk.cpp)
add_executable(search_direct_string pryam_poisk.cpp)