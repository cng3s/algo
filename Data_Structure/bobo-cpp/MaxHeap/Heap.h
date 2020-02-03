//
// Created by c on 18-9-26.
//

#ifndef MAXHEAP_HEAP_H
#define MAXHEAP_HEAP_H

#include <algorithm>
#include <random>
#include <cmath>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp( int idx ) {
        while (idx > 1 && data[idx / 2] < data[idx]) {
            swap(data[idx / 2], data[idx]);
            idx /= 2;
        }
    }

    void shiftDown( int idx ) {

        // 判断idx节点有孩子， 根据堆是完全二叉树的性质只要判断有左孩子即可
        while (2 * idx <= count) {
            int j = 2 * idx; // 在此轮循环中，data[k]和data[j]交换位置
            // 当有右孩子且右孩子大于左孩子的时候
            if (j + 1 <= count && data[j + 1] > data[j])
                j += 1;
            // 如果当前节点比最大的孩子节点还要大，即满足了堆的性质
            // 该节点不需要进行shiftDown操作，直接break退出循环
            if (data[idx] >= data[j])
                break;
            // 不满足堆的性质，交换最大的孩子节点和当前节点来满足
            swap(data[idx], data[j]);
            idx = j;
        }
    }

public:
    MaxHeap(int capacity1) : capacity(capacity1) {
        data = new Item[capacity + 1];
        count = 0;
    }

    MaxHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;
        for (int i = 0; i < n; i ++)
            data[i+1] = arr[i];
        count = n;

        for (int i = count / 2; i >= 1; i --)
            shiftDown(i);
    }

    ~MaxHeap() {
        delete[] data;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[++count] = item;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[1];
        swap (data[1], data[count--]);
        shiftDown(1);
        return ret;
    }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

};

#endif //MAXHEAP_HEAP_H
