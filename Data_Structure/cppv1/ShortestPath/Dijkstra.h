//
// Created by liuyubobobo on 9/28/16.
//

#ifndef INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H
#define INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template <typename Graph, typename Weight>
class Dijkstra {

private:
    Graph &G;
    int s; // 源点

    Weight *distTo; // 长度
    bool *marked; // 是否已经找到
    vector<Edge<Weight>*> from; // 从哪个点来的

public:
    Dijkstra(Graph &graph, int s1) : G(graph), s(s1) {
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); i ++) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        IndexMinHeap<Weight> ipq(G.V()); // 最小索引堆

        // Dijkstra Algorithm
        distTo[s] = Weight();
        marked[s] = true;
        ipq.insert(s, distTo[s]);
        while (!ipq.isEmpty()) {
            int v = ipq.extractMinIndex();

            // distTo[v] 就是 s 到 v 的最短距离
            marked[v] = true;

            // Relaxation
            typename Graph::adjIterator adj(G, v);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);
                if (!marked[w]) {
                    int currentdist = distTo[v] + e->wt();
                    if (from[w] == NULL || currentdist < distTo[w]) {
                        distTo[w] = currentdist;
                        from[w] = e;
                        if (ipq.contain(w))
                            ipq.change(w, distTo[w]);
                        else
                            ipq.insert(w, distTo[w]);
                    }
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] distTo;
        delete[] marked;
    }

    Weight shortedPathTo( int w ) {
        return distTo[w];
    }

    bool hasPathTo( int w ) {
        return marked[w];
    }

    void shortestPath( int w, vector<Edge<Weight>> &vec) {
        /* 存储从起始点到源点通过的路径到vec中 */
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while (e->v() != e->w()) {
            s.push(e);
            e = from[e->v()];
        }
        while (! s.empty()) {
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w) {
        assert( w >= 0 && w <G.V());

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for (int i = 0; i < vec.size(); i ++) {
            cout << vec[i].v() << "->";
            if (i == vec.size() - 1)
                cout << vec[i].w() << endl;
        }
    }
};


#endif //INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H
