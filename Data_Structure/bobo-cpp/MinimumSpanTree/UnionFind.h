//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H


#include <cassert>

namespace UF5 {

/* UnionFind - 快速并查集，使用路径压缩
 * 路径压缩事实上就是一个平衡树的算法，非常简单但有极为明显的效率提升
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

        while (idx != parent[idx]) {
            parent[idx] = parent[parent[idx]]; /* 路径压缩核心代码 */
            idx = parent[idx];
        }
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


#endif //UNIONFIND_UNIONFIND5_H
