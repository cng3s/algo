cmake_minimum_required(VERSION 3.10)
project(ShortestPath)

set(CMAKE_CXX_STANDARD 11)

add_executable(ShortestPath DenseGraph.h Edge.h Dijkstra.h IndexMinHeap.h ReadGraph.h SparseGraph.h main.cpp BellmanFord.h)