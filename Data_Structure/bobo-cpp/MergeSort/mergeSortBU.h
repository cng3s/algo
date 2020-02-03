//
// Created by c on 18-6-21.
//

#ifndef MERGESORT_MERGESORTBU_H
#define MERGESORT_MERGESORTBU_H

#include "mergeSort.h"
#include <algorithm>

// 递归排序自底向上迭代实现
template <typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += 2) // 定义每次遍历子数组的大小，1,2,4,6,8
        for (int i = 0; i + sz < n; i += sz + sz) // 每次遍历并合并两个子数组，所以 i += sz + sz, i + sz 为防止越界
            __merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
}

#endif //MERGESORT_MERGESORTBU_H
