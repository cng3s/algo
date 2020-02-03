//
// Created by c on 6/25/19.
//

#ifndef MINIMUMSPANTREE_KRUSKALMST_H
#define MINIMUMSPANTREE_KRUSKALMST_H

#include <iostream>
#include <vector>

#include "MinHeap.h"
#include "UnionFind.h"
#include "Edge.h"

/* class KruskalMST - 使用Kruskal算法计算最短路径
 * KruskalMST时间复杂度为O(ElogE)，效率低于lazy prim和prim优化算法
 * */
template <typename Graph, typename Weight>
class KruskalMST {

private:
    std::vector<Edge<Weight>> mst; /* 线性存储边信息 */
    Weight w; /* 存储mst总的最小权值 */

public:
    explicit KruskalMST(Graph &gr)
    {
        MinHeap<Edge<Weight>> pq(gr.E());
        for (int i = 0; i < gr.V(); i++) {
            /* 查找每个节点的邻边 */
            typename Graph::adjIter iter(gr, i);
            for (Edge<Weight> *e = iter.begin(); !iter.end(); e = iter.next()) {
                /* 这个判断的目的在于无向图中相同的一条边会被两个节点同时存储两次
                 * 而使用<判断就过滤了一条重复的边，只在堆中保存一次。
                 * */
                if (e->from() < e->to())
                    pq.insert(*e);
            }
        }
        UF5::UnionFind uf(gr.V());
        while (!pq.isEmpty() && mst.size() < gr.V() - 1) {
            Edge<Weight> e = pq.extractMin();
            if (uf.isConnected(e.to(), e.from()))
                continue;

            mst.push_back(e);
            uf.unionElems(e.from(), e.to());
        }

        w = mst[0].weight();
        for (int i = 1; i < mst.size(); i++)
            w += mst[i].weight();

    }

    ~KruskalMST() = default;

    vector<Edge<Weight>> mstEdges()
    {
        return mst;
    }

    Weight result()
    {
        return w;
    }
};

#endif //MINIMUMSPANTREE_KRUSKALMST_H
