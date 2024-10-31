cmake_minimum_required(VERSION 3.10)
project(Cell)

set(CMAKE_CXX_STANDARD 23)


add_executable(Cell
        src/main.cpp
        src/Organelles/Peroxysome.cpp
)

target_include_directories(Cell PRIVATE
        include
        include/Molecules
        include/Organelles
)
