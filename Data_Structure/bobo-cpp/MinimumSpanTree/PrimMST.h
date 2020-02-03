//
// Created by c on 6/24/19.
//

#ifndef MINIMUMSPANTREE_PRIMMST_H
#define MINIMUMSPANTREE_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>

#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

/* class PrimMST - 基于IndexMinHeap优化的Prim最短路径算法
 * 相比于LazyPrimMST从O(Elog(E))提升到O(Elog(V))
 * 且简化了很多复杂的堆操作,使得有较大的效率提升
 * */
template <typename Graph, typename Weight>
class PrimMST {

private:
    Graph &G;
    IndexMinHeap<Weight> ipq; /* 索引最小堆 */
    vector<Edge<Weight>*> edgeTo; /* 存储最小边权值 */
    bool *marked; /* 标记节点是否被访问过 */
    vector<Edge<Weight>> mst; /* 存储所有最小边信息 */
    Weight mstWeight; /* 存储图最小权值结果 */

private:
    void vst(int v)
    {
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::adjIter iter(G, v);

        for (Edge<Weight>* e = iter.begin(); !iter.end(); e = iter.next()) {
            int w = e->other(v);
            if (!marked[w]) { /* 真正要处理的是v连接的另一个节点是未被访问过的 */
                if (!edgeTo[w]) { /* 如果该节点之前就没有被初始化过权值 */
                    ipq.insert(w, e->weight());
                    edgeTo[w] = e;
                }
                else if (e->weight() < edgeTo[w]->weight()) {
                    edgeTo[w] = e;
                    ipq.change(w, e->weight());
                }
            }
        }
    }

public:
    explicit PrimMST(Graph &gr)
        : G(gr), ipq(IndexMinHeap<double>(gr.V()))
    {
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); i++) {
            marked[i] = false;
            edgeTo.push_back(nullptr);
        }
        mst.clear();

        /* Prim核心算法 */
        vst(0);
        while (!ipq.isEmpty()) {
            int v = ipq.extractMinIndex();
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            vst(v);
        }

        mstWeight = mst[0].weight();
        for (int i = 1; i < mst.size(); i++)
            mstWeight += mst[i].weight();
    }

    ~PrimMST()
    {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges()
    {
        return mst;
    }

    Weight result()
    {
        return mstWeight;
    }

};

#endif //MINIMUMSPANTREE_PRIMMST_H
