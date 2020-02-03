#include <iostream>
#include <ctime>
#include <string>

#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;

int main()
{
    string filename = "../testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    std::cout << std::endl;

    Path<SparseGraph> dfs(g, 0);
    std::cout << "DFS : ";
    dfs.showPath(6);

    ShorestPath<SparseGraph> bfs(g, 0);
    std::cout << "BFS : ";
    bfs.showPath(6);

    return 0;
}

// 测试联通分量Component.h
//int main() {
//
//    string filename1 = "../testG1.txt";
//    SparseGraph g1(13, false);
//    ReadGraph<SparseGraph> readGraph1(g1, filename1);
//    Component<SparseGraph> component1(g1);
//    cout << "TestG1.txt, Component Count: " << component1.count() << endl << endl;
//
//    string filename2 = "../testG2.txt";
//    DenseGraph g2(7, false);
//    ReadGraph<DenseGraph> readGraph2(g2, filename2);
//    Component<DenseGraph> component2(g2);
//    cout << "TestG2.txt, Component Count: " << component2.count() << endl << endl;
//
//    return 0;
//}

// 测试稠密图DenseGraph.h和稀疏图SpareGraph.h
//int main()
//{
//
//    int V = 20, E = 100;
//
//    srand(time(NULL));
//
//    /* SparseGraph  O(E)
//     * 存在平行边
//     * */
//    SparseGraph g1(V, false);
//    for (int i = 0; i < E; i++) {
//        int a = rand() % V, b = rand() % V;
//        g1.addEdge(a, b);
//    }
//
//    for (int v = 0; v < V; v++) {
//        cout << v << " : ";
//        SparseGraph::adjIter adj(g1, v);
//        for (int e = adj.begin(); !adj.end(); e = adj.next())
//            cout << e << " ";
//        cout << endl;
//    }
//    cout << endl;
//
//
//    /* DenseGraph O(V^2)
//     * 不存在平行边
//     * */
//    DenseGraph g2(V, false);
//    for (int i = 0; i < E; i++) {
//        int a = rand() % V, b = rand() % V;
//        g2.addEdge(a, b);
//    }
//
//    for (int v = 0; v < V; v++) {
//        cout << v << " : ";
//        DenseGraph::adjIter adj(g2, v);
//        for (int e = adj.begin(); !adj.end(); e = adj.next())
//            cout << e << " ";
//        cout << endl;
//    }
//    cout << endl;
//
//    return 0;
//}