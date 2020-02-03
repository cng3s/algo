//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include <cassert>

namespace UF4 {

/* UnionFind - 快速并查集
 * 添加基于rank的优化操作
 * 维护rank的大小比维护size大小更有科学性
 * 因为需要查找根节点，所以通过rank维护树高比size维护树节点大小更好
 *
 * 这种优化相比于维护size并不快很多甚至有些情况还慢一点
 * 主要是因为unionElems中两棵树相等的情况并不多见
 * 但是维护rank的并查集在一些极端情况下比维护size效率好得多
 * */
class UnionFind {
private:
    int *parent, count;
    int *rank; /* sz[i]表示以i为根的集合中元素的个数 */

public:
    explicit UnionFind(int n) : count(n)
    {
        parent = new int[count];
        rank = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind()
    {
        delete[] (parent);
        delete[] (rank);
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

        /* 快速并集， 维护rank数组 */
        if (rank[idx1_root] < rank[idx2_root])
            parent[idx1_root] = idx2_root;
        else if (rank[idx1_root] > rank[idx2_root])
            parent[idx2_root] = idx1_root;
        else {
            parent[idx2_root] = idx1_root;
            ++rank[idx1_root];
        }
    }
};

}


#endif //UNIONFIND_UNIONFIND4_H
