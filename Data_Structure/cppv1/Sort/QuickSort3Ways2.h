//
// Created by chneg on 2020/2/8.
//

#ifndef SORT_QUICKSORT3WAYS2_H
#define SORT_QUICKSORT3WAYS2_H

#include <ctime>
#include <algorithm>
#include "InsertionSort.h"

template <typename T>
void QuickSort3Ways2(T arr[], int lo, int hi)
{
    if (hi-lo <= 15) {
        insertionSort(arr, lo, hi);
        return;
    }

    swap(arr[lo], arr[rand()%(hi-lo+1)+lo]);
    T pivot_e = arr[lo];
    int lt = lo, i = lo+1, gt = hi+1;
    while (i < gt) {
        while (i < gt && arr[i] < pivot_e) swap(arr[i++], arr[++lt]);
        while (i < gt && arr[i] > pivot_e) swap(arr[i], arr[--gt]);
        while (i < gt && arr[i] == pivot_e) ++i;
    }
    swap(arr[lo], arr[lt]);
    QuickSort3Ways2(arr, lo, lt-1);
    QuickSort3Ways2(arr, gt, hi);
}

template <typename T>
void QuickSort3Ways2(T arr[], int n)
{
    srand(time(nullptr));
    QuickSort3Ways2(arr, 0, n-1);
}

#endif //SORT_QUICKSORT3WAYS2_H
