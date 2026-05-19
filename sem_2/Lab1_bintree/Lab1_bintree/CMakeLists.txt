cmake_minimum_required(VERSION 3.19)
project(Lab1_binary_tree LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Lab1_binary_tree
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    tree.h
    tree.cpp
)

target_link_libraries(Lab1_binary_tree
    PRIVATE
        Qt::Core
        Qt::Widgets
)
