//
// Created by c on 6/22/19.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

/* class Component - 求图联通分量
 * 深度优先遍历 广度优先遍历
 * */
template <typename Graph>
class Component {
private:
    Graph &G;
    bool *vsted; /* visited数组判断该节点是否已经访问过了 */
    int ccnt; /* component count 记录有多少个联通分量，如果联通分量等于图节点数则终止遍历 */
    int *id; /* id用于记录哪两个节点之间是相连的，相连节点id相同，反之不同 */

private:
    /* dfs - 深度优先节点分量联通
     * @v: 节点v
     * */
    void dfs(int v)
    {
        vsted[v] = true;
        id[v] = ccnt; /* 进行联通分量之间的联通记录 */
        typename Graph::adjIter adj(G, v);

        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!vsted[i])
                dfs(i);
        }
    }

public:
    explicit Component(Graph &g) : G(g), ccnt(0)
    {
        vsted = new bool[G.V()];
        id = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            vsted[i] = false;
            id[i] = -1;
        }

        /* 如果该节点没有被访问过则进行深度优先遍历 */
        for (int i = 0; i < G.V(); i++) {
            if (!vsted[i]) {
                dfs(i);
                ++ccnt;
            }
        }
    }

    ~Component()
    {
        delete[] vsted;
        delete[] id;
    }

    int count() const
    {
        return ccnt;
    }

    bool isConnected(int v, int w)
    {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }

};

#endif //GRAPH_COMPONENT_H
