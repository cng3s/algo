//
// Created by chneg on 2020/2/8.
//

#ifndef SORT_QUICKSORT_2_H
#define SORT_QUICKSORT_2_H

#include <algorithm>

template <typename T>
int partition2(T arr[], int lo, int hi)
{
    std::swap(arr[lo], arr[rand()%(hi-lo+1)+lo]);
    T pivot_e = arr[lo];

    int j = lo;
    for (int i = lo+1; i <= hi; ++i) {
        if (arr[i] < pivot_e)
            std::swap(arr[++j], arr[i]);
    }
    std::swap(arr[lo], arr[j]);
    return j;
}

template <typename T>
void QuickSort2(T arr[], int lo, int hi)
{
    if (lo >= hi)
        return;

    int pivot = partition2(arr, lo, hi);
    QuickSort2(arr, lo, pivot-1);
    QuickSort2(arr, pivot+1, hi);
}

template <typename T>
void QuickSort2(T arr[], int n)
{
    srand(time(nullptr));
    QuickSort2(arr, 0, n-1);
}

#endif //SORT_QUICKSORT_2_H
