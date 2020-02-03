//
// Created by c on 18-6-21.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

// 归并排序自顶向下递归实现

// 对两个数组进行合并，范围是arr[l, r)
template <typename T>
void __merge(T arr[], int l, int mid, int r) {

    T aux[r - l + 1]; // 备用数组，用来比较左右子数组并将较小值给arr
    for (int i = l; i <= r; i ++)
        aux[i - l] = arr[i];

    int lcur = l, rcur = mid + 1;
    for (int cur = l; cur <= r; cur ++) {
        if (lcur > mid) { // 当 lcur 大于 mid 时，说明左子数组已经遍历完成， 直接添加右子数组尚未添加的元素
            arr[cur] = aux[rcur - l];
            rcur ++;
        } else if (rcur > r) { // 当 rcur 大于 r 时，说明右子数组已经遍历完成，直接添加左子数组尚未添加的元素
            arr[cur] = aux[lcur - l];
            lcur ++;
        } else if (aux[lcur - l] < aux[rcur - l]) { // 当 aux[lcur] 大于 aux[rcur] 时， arr[cur] 更新为 arr[rcur - l]
            arr[cur] = aux[lcur - l];
            lcur ++;
        } else { // aux[lcur] > aux[rcur] 当 aux[lcur] 大于 aux[rcur] 时， arr[cur]更改为arr[lcur - l]
            arr[cur] = aux[rcur - l];
            rcur ++;
        }
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r) {

    //if (l >= r) // 当 l == r 时，数组中只有一个元素，证明该元素已经有序，直接返回
    //    return;

    if (r - l <= 15) { // 当数据量小的时候，转为插入排序
        insertionSort(arr, l, r);
        return;
    }

    int mid = l / 2 + r / 2; // 防止越界 (l + r) / 2
    __mergeSort(arr, l, mid); // 归并排序左子数组
    __mergeSort(arr, mid + 1, r); // 排序右子数组
    //if (arr[mid] > arr[mid + 1])
        __merge(arr, l, mid, r); // 左右子数组合并
}

template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}


#endif //MERGESORT_MERGESORT_H
