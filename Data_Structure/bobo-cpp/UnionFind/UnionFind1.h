//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFIND1_H
#define UNIONFIND_UNIONFIND1_H

#include <cassert>

namespace UF1 {

class UnionFind {
private:
    int *id;
    int count;

public:
    explicit UnionFind(int n) : count(n)
    {
        id = new int[n];
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    ~UnionFind()
    {
        delete[](id);
    }

    int find(int idx)
    {
        assert(idx>=0 && idx<=count);
        return id[idx];
    }

    bool isConnected(int idx1, int idx2)
    {
        return find(idx1) == find(idx2);
    }

    /* unionElems - idx1和idx2做并集，将所有为id为id[idx1]的元素更改成id[idx2] */
    void unionElems(int idx1, int idx2)
    {
        int idx1_id = find(idx1), idx2_id = find(idx2);

        if (idx1_id == idx2_id)
            return;

        for (int i = 0; i < count; i++)
            if (id[i] == idx1_id)
                id[i] = idx2_id;
    }
};

}

#endif //UNIONFIND_UNIONFIND1_H
