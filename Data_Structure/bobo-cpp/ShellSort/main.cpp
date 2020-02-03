#include <iostream>

#include "InsertionSort.h"
#include "SortTestHelper.h"

using namespace std;


template <typename T>
void shellInsertionSort(T arr[], int n, int start, int gap) {
    // Shell排序的内部函数
    for (int i = start + gap; i < n; i += gap) {
        T e = arr[i];
        int j;
        for (j = i; j - gap >= 0 && arr[j - gap] > e; j -= gap)
            arr[j] = arr[j - gap];
        arr[j] = e;
    }
}

template <typename T>
void shellSort(T arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = 0; i < gap; i ++)
            shellInsertionSort(arr, n, i, gap);
}

int main() {

    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Shell Sort", shellSort, arr, n);
    SortTestHelper::testSort("Insertion Sort: ", insertionSort, arr2, n);

    delete[] arr;
    delete[] arr2;


    return 0;
}