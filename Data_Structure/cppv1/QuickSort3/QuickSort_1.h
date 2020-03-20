//
// Created by chneg on 2020/2/8.
//

#ifndef SORT_QUICKSORT_1_H
#define SORT_QUICKSORT_1_H

template <typename T>
int partition1(T arr[], int lo, int hi)
{
    std::swap(arr[lo], arr[rand()%(hi-lo+1)+lo]);
    T pivot_e = arr[lo];
    while (lo < hi) {
        while (lo < hi && arr[hi] >= pivot_e) --hi;
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] <= pivot_e) ++lo;
        arr[hi] = arr[lo];
    }
    arr[lo] = pivot_e;
    return lo;
}

template <typename T>
void QuickSort1(T arr[], int lo, int hi)
{
    if (lo >= hi)
        return;

    int pivot = partition1(arr, lo, hi);

    QuickSort1(arr, lo, pivot-1);
    QuickSort1(arr, pivot+1, hi);
}

template <typename T>
void QuickSort1(T arr[], int n)
{
    srand(time(nullptr));
    QuickSort1(arr, 0, n-1);
}

#endif //SORT_QUICKSORT_1_H
