//
// Created by c on 18-6-20.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    // 生成有 n 个元素的随机数组，每个数组的随机范围是[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i ++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    template <typename T>
    void printArray(T arr, int n) {
        for (int i = 0; i < n; i ++)
            cout << arr[i] << " ";
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n) {
        // 检查数组是否有序
        for (int i = 0; i < n - 1; i ++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        // sortName: 排序算法名字，方便打印输出
        // *sort: 排序函数作参数
        // arr[]: 被排序的数组
        // n: 数组长度

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
}

#endif //SELECTIONSORT_SORTTESTHELPER_H
