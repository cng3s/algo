//
// Created by chneg on 2020/2/8.
//

#ifndef SORT_QUICKSORT3WAYS_H
#define SORT_QUICKSORT3WAYS_H

#include "InsertionSort.h"
#include <algorithm>

template <typename T>
void QuickSort3Ways(T arr[], int lo, int hi)
{
    if (hi-lo <= 15) {
        insertionSort(arr, lo, hi);
        return;
    }

    swap(arr[lo], arr[rand()%(hi-lo+1)+lo]);
    T pivot_e = arr[lo];
    int lt = lo; // 排序过程中lt 指向最后一个 < pivot_e的元素
    int gt = hi+1; // gt 指向第一个 > pivot_e的元素
    int i = lo+1; // i 指向将要与 pivot_e比较的元素
    // arr[lo+1, lt] < pivot_e , arr[lt+1, i-1] == pivot_e , arr[gt, r] > pivot_e
    while (i < gt) {
        if (arr[i] < pivot_e)
            swap(arr[i++], arr[++lt]); // lt与i接壤，要++lt, ++i来更新小于pivot_e 和 等于pivot_e的数组大小
        else if (arr[i] > pivot_e)
            swap(arr[i], arr[--gt]); // 这里i不用维护，因为i和gt不接壤。只要更新大于pivot_e的数组大小即可
        else
            ++i; // 只要更新等于pivot_e的数组大小即可
    }

    swap(arr[lo], arr[lt]); // 排好序lt 指向第一个 == pivot_e的元素
    QuickSort3Ways(arr, lo, lt-1);
    QuickSort3Ways(arr, gt, hi);
}

template <typename T>
void QuickSort3Ways(T arr[], int n)
{
    srand(time(nullptr));
    QuickSort3Ways(arr, 0, n-1);
}

#endif //SORT_QUICKSORT3WAYS_H
