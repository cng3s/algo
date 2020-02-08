cmake_minimum_required(VERSION 3.10)
project(Sort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -O3)

add_executable(Sort main.cpp QuickSort_1.h QuickSort_2.h MergeSort.h InsertionSort.h QuickSort2Ways.h QuickSort3Ways.h QuickSort3Ways2.h)