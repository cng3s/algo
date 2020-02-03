#include <iostream>
#include "Heap.h"

using namespace std;

template <typename T>
void __shiftDown(T arr[], int n, int idx) {
    // arr从0开始索引，进行原地堆排序
    // 2*idx+1是idx的左孩子节点
    // 因为从0开始索引，相应的 2*idx 改为 2*idx+1
    while (2*idx+1 < n) {
        int j = 2 * idx + 1;
        // 是否存在右孩子并且右孩子是否比左孩子大
        // 如果是换为右孩子做判断
        if (j + 1 < n && arr[j+1] > arr[j])
            j += 1;
        // 是否已经大于最大的孩子了
        // 如果大于最大的孩子，该节点满足堆性质，直接break
        if (arr[idx] >= arr[j])
            break;

        swap(arr[idx], arr[j]);
        idx = j;
    }
}

template <typename T>
void heapSort1(T arr[], int n) {
    // heapify
    for (int i = (n - 1) / 2; i >= 0; i --)
        __shiftDown(arr, n, i);

    for (int i = n - 1; i > 0; i --) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    //cout << maxheap.size() << endl;

    srand(time(NULL));
    for (int i = 0; i < 15; i ++)
        maxheap.insert(rand() % 100);

    while (!maxheap.isEmpty())
        cout << maxheap.extractMax() << " ";
    cout << endl;

    return 0;
}