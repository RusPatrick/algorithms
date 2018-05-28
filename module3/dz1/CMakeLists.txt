cmake_minimum_required(VERSION 3.10)
project(dz1)

set(CMAKE_CXX_STANDARD 17)

add_executable(dz1 src/main.cpp include/IGraph.h src/ListGraph.cpp include/ListGraph.h include/MatrixGraph.h src/MatrixGraph.cpp src/SetGraph.cpp include/SetGraph.h src/ArcGraph.cpp include/ArcGraph.h)