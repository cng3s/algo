#include <iostream>
#include <string>
#include <iomanip>

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"

using namespace std;

// 测试prim算法
int main()
{
    std::string filename = "../testG1.txt";
    int V = 8;

    SparseGraph<double> g2 = SparseGraph<double> (V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);

    // test lazy primt minimum span tree
    cout << "Test Lazy Prim MST: " << endl;
    LazyPrimMST<SparseGraph<double>, double> lazy(g2);
    vector<Edge<double>> mst = lazy.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is : " << lazy.result() << endl << endl;

    // test primt minimum span tree
    cout << "Test Lazy Prim MST: " << endl;
    PrimMST<SparseGraph<double>, double>prim(g2);
    mst = prim.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is : " << prim.result() << endl;

    // test kruskal mst
    cout << "Test Kruskal MST:" << endl;
    KruskalMST<SparseGraph<double>, double> kruskal(g2);
    mst = kruskal.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is : " << kruskal.result() << endl;

    return 0;
}

// 测试带权的DenseGraph和SpareGraph
//int main()
//{
//    std::string filename = "../testG1.txt";
//    int V = 8;
//    cout << fixed << setprecision(2);
//
//    // Test Weight Dense Graph
//    DenseGraph<double> g1 = DenseGraph<double> (V, false);
//    ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
//    g1.show();
//    cout << endl;
//
//    // Test Weight Dense Graph
//    SparseGraph<double> g2 = SparseGraph<double> (V, false);
//    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
//    g2.show();
//    cout << endl;
//
//    return 0;
//}