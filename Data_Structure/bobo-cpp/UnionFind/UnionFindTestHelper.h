//
// Created by c on 6/21/19.
//

#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H


#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"
#include "UnionFind6.h"

using namespace std;

namespace UnionFindTestHelper {

    /* testUF1 - 测试UnionFind1类的函数
     * 随机抽取元素调用unionElems进行相同元素ID的连接 O(n)
     * 然后随机判断两个元素是否连接 O(1)
     * */
    void testUF1(int n)
    {
        srand(time(NULL));
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.unionElems(idx1, idx2);
        }

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.isConnected(idx1, idx2);
        }

        time_t endTime = clock();

        cout << "UF1, " << 2*n << " ops, " << double(endTime-startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUF2(int n)
    {
        srand(time(NULL));
        UF2::UnionFind uf = UF2::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.unionElems(idx1, idx2);
        }

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.isConnected(idx1, idx2);
        }

        time_t endTime = clock();

        cout << "UF2, " << 2*n << " ops, " << double(endTime-startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUF3(int n)
    {
        srand(time(NULL));
        UF3::UnionFind uf = UF3::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.unionElems(idx1, idx2);
        }

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.isConnected(idx1, idx2);
        }

        time_t endTime = clock();

        cout << "UF3, " << 2*n << " ops, " << double(endTime-startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUF4(int n)
    {
        srand(time(NULL));
        UF4::UnionFind uf = UF4::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.unionElems(idx1, idx2);
        }

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.isConnected(idx1, idx2);
        }

        time_t endTime = clock();

        cout << "UF4, " << 2*n << " ops, " << double(endTime-startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUF5(int n)
    {
        srand(time(NULL));
        UF5::UnionFind uf = UF5::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.unionElems(idx1, idx2);
        }

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.isConnected(idx1, idx2);
        }

        time_t endTime = clock();

        cout << "UF5, " << 2*n << " ops, " << double(endTime-startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUF6(int n)
    {
        srand(time(NULL));
        UF6::UnionFind uf = UF6::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.unionElems(idx1, idx2);
        }

        for (int i = 0; i < n; i++) {
            int idx1 = rand() % n, idx2 = rand() % n;
            uf.isConnected(idx1, idx2);
        }

        time_t endTime = clock();

        cout << "UF6, " << 2*n << " ops, " << double(endTime-startTime) / CLOCKS_PER_SEC << endl;
    }
}

#endif //UNIONFIND_UNIONFINDTESTHELPER_H
