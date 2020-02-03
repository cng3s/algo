cmake_minimum_required(VERSION 3.10)
project(MaxHeap)

set(CMAKE_CXX_STANDARD 11)

add_executable(MaxHeap main.cpp IndexHeap.h Heap.h InsertionSort.h HeapSort.h)