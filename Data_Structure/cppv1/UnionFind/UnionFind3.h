//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <cassert>

namespace UF3 {

/* UnionFind - 快速并查集
 * 添加基于size的优化操作
 * 该优化维护树的大小，将小树接到大树上，以增加找根节点的效率
 * */
class UnionFind {
private:
    int *parent, count;
    int *sz; /* sz[i]表示以i为根的集合中元素的个数 */

public:
    explicit UnionFind(int n) : count(n)
    {
        parent = new int[count];
        sz = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    ~UnionFind()
    {
        delete[] (parent);
        delete[] (sz);
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

        /* 快速并集， 维护sz数组 */
        if (sz[idx1_root] < sz[idx2_root]) {
            parent[idx1_root] = idx2_root;
            sz[idx2_root] += sz[idx1_root];
        } else {
            parent[idx2_root] = idx1_root;
            sz[idx1_root] += sz[idx2_root];
        }
    }
};

}

#endif //UNIONFIND_UNIONFIND3_H
