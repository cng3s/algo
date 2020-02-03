//
// Created by c on 18-6-20.
//

#ifndef SHELLSORT_INSERTIONSORT_H
#define SHELLSORT_INSERTIONSORT_H

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i ++) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j --)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}

#endif //SHELLSORT_INSERTIONSORT_H
