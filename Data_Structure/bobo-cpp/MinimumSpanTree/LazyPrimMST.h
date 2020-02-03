//
// Created by c on 6/24/19.
//

#ifndef MINIMUMSPANTREE_LAZYPRIMMST_H
#define MINIMUMSPANTREE_LAZYPRIMMST_H

#include <vector>

#include "MinHeap.h"
#include "Edge.h"

/* class LazyPrimMST - Lazy Prim Minimum Span Tree
 * Lazy Prim算法实现最小分割树，利用切分定理完成
 * */
template <typename Graph, typename Weight>
class LazyPrimMST {

private:
    Graph &G;
    MinHeap<Edge<Weight>> pq; /* priority queue */
    bool *marked; /* 标记点是否被访问过，即是否是切分节点 */
    std::vector<Edge<Weight>> mst; /* 线性存储最小边信息的结果 */
    Weight mstWeight; /* 存储总的图最小权值 */

private:
    /* vst - 访问未访问过的节点v，并添加和v连接的横切边到堆中 */
    void vst(int v)
    {
        assert(!marked[v]); /* 这个v应该是一个未被访问过的节点　*/
        marked[v] = true; /* 设置为访问过的节点 */
        typename Graph::adjIter iter(G, v);
        for (Edge<Weight>* e = iter.begin(); !iter.end(); e = iter.next()) {
            /* 如果ｖ连接的另一个节点是一个未访问过的,则找到了横切边　*/
            if (!marked[e->other(v)])
                pq.insert(*e);
        }
    }

public:
    explicit LazyPrimMST(Graph &g)
        : G(g), pq(MinHeap<Edge<Weight>>(g.E()))
    {
        marked = new bool[G.V()];

        for (int i = 0; i < G.V(); i++)
            marked[i] = false;
        mst.clear();

        /* Lazy Prim */
        vst(0);
        while (!pq.isEmpty()) {
            Edge<Weight> e = pq.extractMin();
            /* 如果边两侧都被访问过了或都没访问过则忽略 */
            if (marked[e.from()] == marked[e.to()])
                continue;

            mst.push_back(e);
            if (!marked[e.to()])
                vst(e.to());
            else
                vst(e.from());
        }

        mstWeight = mst[0].weight();
        for (int i = 1; i < mst.size(); i++)
            mstWeight += mst[i].weight();
    }

    ~LazyPrimMST()
    {
        delete[] marked;
    }

    std::vector<Edge<Weight>> mstEdges()
    {
        return mst;
    }

    Weight result()
    {
        return mstWeight;
    }

};

#endif //MINIMUMSPANTREE_LAZYPRIMMST_H
