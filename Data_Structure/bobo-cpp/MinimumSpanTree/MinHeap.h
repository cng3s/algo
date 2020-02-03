//
// Created by c on 6/24/19.
//

#ifndef MINIMUMSPANTREE_MINHEAP_H
#define MINIMUMSPANTREE_MINHEAP_H

#include <algorithm>
#include <cassert>

template <typename Item>
class MinHeap {

private:
    Item *data;
    int cnt, cap; /* cnt: 当前堆中元素数量; cap: 元素数量阈值 */

private:
    void shiftUp(int k)
    {
        while (k>1 && data[k/2]>data[k]) {
            std::swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k)
    {
        while (2*k <= cnt) {
            int j = 2 * k;
            if (j+1 <= cnt && data[j+1]<data[j])
                ++j;
            if (data[k] <= data[j])
                break;
            std::swap(data[k], data[j]);
            k = j;
        }
    }

public:
    explicit MinHeap(int c)
        : cap(c), cnt(0)
    {
        data = new Item[cap+1];
    }

    explicit MinHeap(Item arr[], int c)
        : cap(c), cnt(c)
    {
        data = new Item[cap+1];

        for (int i = 0; i < cap; i++)
            data[i+1] = arr[i];
        for (int i = cnt/2; i >= 1; i--)
            shiftDown(i);
    }

    ~MinHeap()
    {
        delete[] data;
    }

    int size()
    {
        return cnt;
    }

    bool isEmpty()
    {
        return cnt == 0;
    }

    void insert(Item item)
    {
        assert(cnt+1 <= cap);
        data[cnt+1] = item;
        shiftUp(++cnt);
    }

    /* extractMin - 从最小堆中取出堆顶元素，即堆中存储的最小元素　*/
    Item extractMin()
    {
        Item ret = getMin();
        std::swap(data[1], data[cnt]);
        cnt--;
        shiftDown(1);
        return ret;
    }

    Item getMin()
    {
        assert(cnt > 0);
        return data[1];
    }

};

#endif //MINIMUMSPANTREE_MINHEAP_H
