//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFIND6_H
#define UNIONFIND_UNIONFIND6_H


#include <cassert>

namespace UF6 {

/* UnionFind - 快速并查集，使用更优化的路径压缩
 * 这个函数中路径压缩到所有树只有两层，路径搜索效率达到最优化
 * 但实际上这种做法不一定是最优的，因为递归调用函数需要额外的开销
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
        /* 更优化的路径压缩算法实现
         * 采用递归思想，递归到根节点终止然后返回，每个节点都连接到根节点
         * */
        return (idx != parent[idx]) ? parent[idx] = find(parent[idx])
                                    : parent[idx];
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


#endif //UNIONFIND_UNIONFIND6_H
