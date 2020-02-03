//
// Created by c on 6/21/19.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

/* 稠密图 - 邻接矩阵 */
template <typename Weight>
class DenseGraph {
private:
    int vertex, edge; /* 点数 、边数 */
    bool directed;
    vector<vector<Edge<Weight> *>> g;

public:
    explicit DenseGraph(int n, bool d)
        : vertex(n), edge(0), directed(d)
    {
        for (int i = 0; i < n; i++)
            g.emplace_back(vector<Edge<Weight> *>(n, nullptr));
    }

    ~DenseGraph()
    {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++)
                if (g[i][j] != nullptr)
                    delete g[i][j];
        }
    }

    int V()
    {
        return vertex;
    }

    int E()
    {
        return edge;
    }

    void addEdge(int y, int x, Weight w)
    {
        /* xxx 可直接修改w的值而不需要进行删除再创建
         * 但Edge中w是私有的
         * */
        if (hasEdge(y, x)) {
            delete g[y][x];
            if (!directed)
                delete g[x][y];
            edge--;
        }

        g[y][x] = new Edge<Weight>(y, x, w);
        if (!directed) /* 无向图的情况 */
            g[x][y] = g[x][y] = new Edge<Weight>(x, y, w);

        edge++;
    }

    bool hasEdge(int y, int x)
    {
        assert(y >= 0 && y < vertex);
        assert(x >= 0 && x < vertex);
        return g[y][x] != nullptr;
    }

    void show()
    {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                if (g[i][j])
                    cout << g[i][j]->weight() << "\t";
                else
                    cout << "NULL\t";
            }
            cout << endl;
        }
    }

    /* class adjIter - 稠密图的迭代器 */
    class adjIter {
    public:
        DenseGraph &G;
        int v;
        int idx;

    public:
        adjIter(DenseGraph &gr, int v1)
            : G(gr), v(v1), idx(-1)
        {}

        Edge<Weight>* begin()
        {
            idx = -1;

            return next();
        }

        Edge<Weight>* next()
        {
            for (idx += 1; idx < G.V(); idx++)
                if (G.g[v][idx])
                    return G.g[v][idx];

            return nullptr;
        }

        bool end()
        {
            return idx >= G.V();
        }
    };

};

#endif //GRAPH_DENSEGRAPH_H
