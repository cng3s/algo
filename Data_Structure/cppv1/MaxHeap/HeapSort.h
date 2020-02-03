//
// Created by c on 18-9-26.
//

#ifndef MAXHEAP_HEAPSORT_H
#define MAXHEAP_HEAPSORT_H

#include "Heap.h"


template <typename T>
void headSort1(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    // 将数组中的元素插入到堆中
    // 堆会自动在插入的过陈中为元素排序
    for (int i = 0; i < n; i ++)
        maxheap.insert(arr[i]);
    // 将堆中的最大元素解压出来，经过n次解压arr就有从小到大的顺序元素
    for (int i = n - 1; i >= 0; i --)
        arr[i] = maxheap.extractMax();
}

template <typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; i --)
        arr[i] = maxheap.extractMax();
}


#endif //MAXHEAP_HEAPSORT_H
