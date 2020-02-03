//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <cassert>

namespace UF2 {

/* UnionFind - 快速并查集 */
class UnionFind {
private:
    int *parent, count;

public:
    explicit UnionFind(int n) : count(n)
    {
        parent = new int[count];
        for (int i = 0; i < count; i++)
            parent[i] = i;
    }

    ~UnionFind()
    {
        delete[](parent);
    }

    /* find - 查找idx根节点的id */
    int find(int idx)
    {
        assert(idx >= 0 && idx < count);

        while (idx != parent[idx])
            idx = parent[idx];
        return idx;
    }

    bool isConnected(int idx1, int idx2)
    {
        return find(idx1) == find(idx2);
    }

    void unionElems(int idx1, int idx2)
    {
        int idx1_root = find(idx1), idx2_root = find(idx2);

        if (idx1_root == idx2_root)
            return;

        parent[idx1_root] = idx2_root;
    }
};

}

#endif //UNIONFIND_UNIONFIND2_H
