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
class IndexMaxHeap {
private:
    Item *data;
    int *indexes;
    int count;
    int capacity;


    void shiftUp( int idx ) {
        while (idx > 1 && data[indexes[idx / 2]] < data[indexes[idx]]) {
            swap(indexes[idx / 2], indexes[idx]);
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
            if (data[indexes[idx]] >= data[indexes[j]])
                break;
            // 不满足堆的性质，交换最大的孩子节点和当前节点来满足
            swap(indexes[idx], indexes[j]);
            idx = j;
        }
    }

public:
    IndexMaxHeap(int capacity1) : capacity(capacity1) {
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        count = 0;
    }

    IndexMaxHeap(Item arr[], int n) {
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
        delete[] indexes;
    }

    // 对传入的用户而言是从0开始索引的
    void insert(int idx, Item item) {
        assert(count + 1 <= capacity);
        assert( idx + 1 >= 1 && idx + 1 <= capacity);

        idx += 1;
        data[idx] = item;
        indexes[++count] = idx;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[indexes[1]];
        swap (data[indexes[1]], data[indexes[count--]]);
        shiftDown(1);
        return ret;
    }

    Item extractMaxIndex() {
        assert(count > 0);

        // indexes[1] - 1 目的是将从1开始的索引转为从0开始的索引
        // 这样保证了用户可以接收到正确的索引
        int ret = indexes[1] - 1;
        swap(data[indexes[1]], data[indexes[count--]]);
        count --;
        shiftDown(1);

        return ret;
    }

    Item getItem(int idx) {
        // 得到索引的元素
        return data[idx + 1];
    }

    void change(int i, Item newItem) {
        // 更正索引为1开始计数
        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j 表示 data[i]在堆中的位置
        // 再shiftUp(j), shiftDown(j)
        for (int j = 1; j <= count; j++) {
            if (indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
    }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

};

#endif //MAXHEAP_HEAP_H
