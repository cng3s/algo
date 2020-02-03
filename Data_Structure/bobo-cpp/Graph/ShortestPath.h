//
// Created by c on 6/22/19.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include <cassert>
#include <queue>
#include <iostream>
#include <stack>

/* class ShortestPath - 最短路径算法
 * 使用广度优先遍历一定可以找到最短路径
 *
 * 当有多条最短路径时如何展示出所有的最短路径？
 *
 * 稀疏图： O(V+E)
 * 稠密图: O(V^2)
 * */
template <typename Graph>
class ShorestPath {

private:
    Graph &G;
    int begv;
    bool *vsted;
    int *from;
    int *ord; /* 记录begv到具体的每一个节点的最短路径值 */

public:
    explicit ShorestPath(Graph &gr, int b) : G(gr), begv(b)
    {
        assert(begv >= 0 && begv < gr.V());

        vsted = new bool[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            vsted[i] = false;
            from[i] = ord[i] = -1;
        }

        /* 无向图最短路径核心算法
         * 其核心思想就是广度优先遍历算法
         * */
        std::queue<int> q;
        q.push(begv);
        vsted[begv] = true;
        ord[begv] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            typename Graph::adjIter iter(G, v);
            for (int i = iter.begin(); !iter.end(); i = iter.next()) {
                if (!vsted[i]) {
                    q.push(i);
                    vsted[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }

    }

    ~ShorestPath()
    {
        delete[] vsted;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int v)
    {
        assert(v >= 0 && v < G.V());
        return vsted[v];
    }

    void path(int dst, std::vector<int> &vec)
    {
        assert(dst >= 0 && dst < G.V());

        std::stack<int> s;
        int d = dst;

        while (d != -1) {
            s.push(d);
            d = from[d];
        }
        vec.clear();

        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int dst)
    {
        assert(dst >= 0 && dst < G.V());

        std::vector<int> vec;
        path(dst, vec);

        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i];
            if (i == vec.size()-1)
                std::cout << std::endl;
            else
                std::cout << " -> ";
        }
    }

    int length(int dst)
    {
        assert(dst >= 0 && dst < G.V());
        return ord[dst];
    }
};

#endif //GRAPH_SHORTESTPATH_H
