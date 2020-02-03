//
// Created by c on 6/22/19.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* 稀疏图 - 邻接表 */
class SparseGraph {
private:
    int vertex, edge;
    bool directed;
    vector<vector<int>> g;

public:
    explicit SparseGraph(int v, bool d)
        : vertex(v), directed(d), edge(0)
    {
        for (int i = 0; i < vertex; i++)
            g.emplace_back(vector<int>());
    }

    ~SparseGraph() = default;

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

        for (int i : g[v1])
            if (i == v2)
                return true;

        return false;
    }

    /* addEdge - 在v1,v2位置添加一条新的边
     * 这里的addEdge中没有判断hasEdge(v1, v2)
     * 其原因在于hasEdge会导致addEdge复杂度提升到O(n)
     * 所以我们默认先允许拥有平行边
     * 将所有的边都加进来以后再进行一个综合的处理去除平行边
     * */
    void addEdge(int v1, int v2)
    {
        assert(v1 >= 0 && v1 < vertex);
        assert(v2 >= 0 && v2 < vertex);

        g[v1].push_back(v2);
        if (v1 != v2 && !directed)
            g[v2].push_back(v1);
        edge++;
    }

    void show()
    {
        for (int i = 0; i < vertex; i++) {
            cout << "vertex " << i << ": \t";
            for (int j : g[i])
                cout << j << "\t";
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

        int begin()
        {
            idx = 0;

            return (!G.g[v].empty()) ? G.g[v][idx] : -1;
        }

        int next()
        {
            return (++idx) < G.g[v].size() ? G.g[v][idx] : -1;
        }

        bool end()
        {
            return idx >= G.g[v].size();
        }

    };
};

#endif //GRAPH_SPARSEGRAPH_H
