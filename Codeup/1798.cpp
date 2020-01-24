#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define CAPCITY 10000
bool graph[CAPCITY][CAPCITY];

int main()
{
    int C1, C2, i, j, count = 0;

    while (scanf("%d%d", &C1, &C2)) {
        if (C1 != C2) {
            graph[C1][C2] = true;
            graph[C2][C1] = true;
        }
    }

    // 因为是无向图，只需遍历图矩阵的对角矩阵
    for (i = 0; i < CAPCITY; ++i) {
        for (j = i; j < CAPCITY; ++j) {
            if (graph[i][j])
                count += 1;
        }
    }

    printf("%d", count);

    return 0;
}