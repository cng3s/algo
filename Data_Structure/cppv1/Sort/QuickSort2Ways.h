//
// Created by chneg on 2020/2/8.
//

#ifndef SORT_QUICKSORT2WAYS_H
#define SORT_QUICKSORT2WAYS_H

#include <algorithm>
#include <ctime>

template <typename T>
int partition2Ways(T arr[], int lo, int hi)
{
    std::swap(arr[lo], arr[rand()%(hi-lo+1)+lo]);
    T pivot_e = arr[lo];

    int i = lo+1, j = hi;
    while (true) {
        while (i <= hi && arr[i] < pivot_e) ++i;
        while (j >= lo+1 && arr[j] > pivot_e) --j;
        if (i > j) break;
        std::swap(arr[i++], arr[j--]);
    }
}

template <typename T>
void QuickSort2Ways(T arr[], int lo, int hi)
{
    if (lo >= hi)
        return;

    int pivot = partition2(arr, lo, hi);
    QuickSort2Ways(arr, lo, pivot-1);
    QuickSort2Ways(arr, pivot+1, hi);
}

template <typename T>
void QuickSort2Ways(T arr[], int n)
{
    srand(time(nullptr));
    QuickSort2Ways(arr, 0, n-1);
}
#endif //SORT_QUICKSORT2WAYS_H
