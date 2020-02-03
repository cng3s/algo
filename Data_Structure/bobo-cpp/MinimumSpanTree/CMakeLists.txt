cmake_minimum_required(VERSION 3.14)
project(MinimumSpanTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(MinimumSpanTree main.cpp DenseGraph.h Edge.h MinHeap.h LazyPrimMST.h IndexMinHeap.h PrimMST.h KruskalMST.h)