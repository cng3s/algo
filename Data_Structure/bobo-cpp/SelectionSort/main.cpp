#include <iostream>
using namespace std;

#include "Student.h"
#include "SortTestHelper.h"

template <typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[minIndex], arr[i]);
    }
}

int main() {

    int n = 100000;

    { // test case
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
//        selectionSort(arr, n);
//        SortTestHelper::printArray(arr, n);
        SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
        delete[] arr;
    }

//    {// test case
//        int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//        selectionSort(a, 10);
//        SortTestHelper::printArray(a, 10);
//    }
//
//    {//test case
//        float b[4] = {4.4, 3.3, 2.2, 1.1};
//        selectionSort(b, 4);
//        SortTestHelper::printArray(b, 4);
//    }
//
//    {// test case
//        string c[4] = {"D", "C", "B", "A"};
//        selectionSort(c, 4);
//        SortTestHelper::printArray(c, 4);
//    }
//
//    {// test case
//        struct Student student[4] = {{"D", 90},
//                                     {"C", 80},
//                                     {"B", 60},
//                                     {"A", 60}};
//        selectionSort(student, 4);
//        SortTestHelper::printArray(student, 4);
//    }


    return 0;
}