//
// Created by c on 6/22/19.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <cassert>
#include <iostream>
#include <vector>
#include <stack>

/* class Path - 图路径寻找 */
template <typename Graph>
class Path {

private:
    Graph &G;
    int begv; /* 起点 */
    bool *vsted;
    int *from; /* 每访问一个节点存储从哪个节点到达这个节点的 */

private:
    void dfs(int v)
    {
        vsted[v] = true;

        typename Graph::adjIter iter(G, v);

        for (int i = iter.begin(); !iter.end(); i = iter.next()) {
            if (!vsted[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    explicit Path(Graph &gr, int b) : G(gr), begv(b)
    {
        assert(begv >= 0 && begv < G.V());

        from = new int[G.V()];
        vsted = new bool[G.V()];

        for (int i = 0; i < G.V(); i++) {
            vsted[i] = false;
            from[i] = -1;
        }

        /* 寻路算法 */
        dfs(b);
    }

    ~Path()
    {
        delete[] vsted;
        delete[] from;
    }

    bool hasPath(int w)
    {
        assert(w >= 0 && w < G.V());
        return vsted[w];
    }

    /* path - 寻找从begv到dst的一条路径并存储在vec中
     * 其思路在逆向查找dst到begv的from数组
     * */
    void path(int dst, std::vector<int> &vec)
    {
        std::stack<int> s;
        int d = dst;

        while (d != -1) { /* 源节点值为-1，故到达源节点后终止 */
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
};

#endif //GRAPH_PATH_H
