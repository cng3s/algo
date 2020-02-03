//
// Created by c on 6/21/19.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* 稠密图 - 邻接矩阵 */
class DenseGraph {
private:
    int vertex, edge; /* 点数 、边数 */
    bool directed;
    vector<vector<bool>> g;

public:
    explicit DenseGraph(int n, bool d)
        : vertex(n), edge(0), directed(d)
    {
        for (int i = 0; i < n; i++)
            g.emplace_back(vector<bool>(n, false));
    }

    ~DenseGraph() = default;

    int V()
    {
        return vertex;
    }

    int E()
    {
        return edge;
    }

    void addEdge(int y, int x)
    {
        if (hasEdge(y, x))
            return;

        g[y][x] = true;
        if (!directed) /* 无向图的情况 */
            g[x][y] = true;

        edge++;
    }

    bool hasEdge(int y, int x)
    {
        assert(y >= 0 && y < vertex);
        assert(x >= 0 && x < vertex);
        return g[y][x];
    }

    void show()
    {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++)
                cout << g[i][j] << "\t";
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

        int begin()
        {
            idx = -1;

            return next();
        }

        int next()
        {
            for (idx += 1; idx < G.V(); idx++)
                if (G.g[v][idx])
                    return idx;

            return -1;
        }

        bool end()
        {
            return idx >= G.V();
        }
    };

};

#endif //GRAPH_DENSEGRAPH_H
