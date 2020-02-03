//
// Created by c on 6/22/19.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

#include "Edge.h"

using namespace std;

/* 稀疏图 - 邻接表 */
template <typename Weight>
class SparseGraph {
private:
    int vertex, edge;
    bool directed;
    vector<vector<Edge<Weight> *>> g;

public:
    explicit SparseGraph(int v, bool d)
        : vertex(v), directed(d), edge(0)
    {
        for (int i = 0; i < vertex; i++)
            g.emplace_back(vector<Edge<Weight> *>());
    }

    ~SparseGraph()
    {
        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < g[i].size(); j++)
                delete g[i][j];
    }

    int V()
    {
        return vertex;
    }

    int E()
    {
        return edge;
    }

    /* hasEdge - 判断v1,v2是否有一条边
     * 稀疏图需要遍历v1,v2来判断
     * */
    bool hasEdge(int v1, int v2)
    {
        assert(v1 >= 0 && v1 < vertex);
        assert(v2 >= 0 && v2 < vertex);

        for (int i = 0; i < g[v1].size(); i++)
            if (g[v1][i]->other(v1) == v2)
                return true;
        return false;
    }

    /* addEdge - 在v1,v2位置添加一条新的边
     * 这里的addEdge中没有判断hasEdge(v1, v2)
     * 其原因在于hasEdge会导致addEdge复杂度提升到O(n)
     * 所以我们默认先允许拥有平行边
     * 将所有的边都加进来以后再进行一个综合的处理去除平行边
     * */
    void addEdge(int v1, int v2, Weight w)
    {
        assert(v1 >= 0 && v1 < vertex);
        assert(v2 >= 0 && v2 < vertex);

        g[v1].push_back(new Edge<Weight>(v1, v2, w));
        if (v1 != v2 && !directed)
            g[v2].push_back(new Edge<Weight>(v2, v1, w));
        edge++;
    }

    void show()
    {
        for (int i = 0; i < vertex; i++) {
            cout << "vertex " << i << ": \t";
            for (int j = 0; j < g[i].size(); j++)
                cout << "( to:" << g[i][j]->to() << ", weight: "
                    << g[i][j]->weight() << ")\t";
            cout << endl;
        }
    }

    /* class adjIter - 稀疏图迭代器实现 */
    class adjIter {
    public:
        SparseGraph &G; /* 图 */
        int v; /* 第v个节点 */
        int idx; /* 迭代器迭代位置的索引值 */

    public:
        adjIter(SparseGraph &gr, int v1)
            : G(gr), v(v1), idx(0)
        {}

        Edge<Weight>* begin()
        {
            idx = 0;

            return (!G.g[v].empty()) ? G.g[v][idx] : nullptr;
        }

        Edge<Weight>* next()
        {
            return (++idx) < G.g[v].size() ? G.g[v][idx] : nullptr;
        }

        bool end()
        {
            return idx >= G.g[v].size();
        }

    };
};

#endif //GRAPH_SPARSEGRAPH_H
