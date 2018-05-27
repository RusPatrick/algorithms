cmake_minimum_required(VERSION 3.10)
project(dz1)

set(CMAKE_CXX_STANDARD 17)

add_executable(dz1 main.cpp ListGraph.cpp IGraph.h ListGraph.h MatrixGraph.h MatrixGraph.cpp SetGraph.cpp SetGraph.h ArcGraph.cpp ArcGraph.h)