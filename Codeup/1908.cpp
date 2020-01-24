#pragma warning(disable : 4996)
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

#define CAPCITY 1001
#define INF INT_MAX
int n, m;
bool graph[CAPCITY][CAPCITY];
bool marked[CAPCITY];
vector<bool> res;

void DFS(int index)
{
    marked[index] = true;
    for (int i = 1; i <= n; ++i) {
        if (graph[index][i] != false && marked[i] == false)
            DFS(i);
    }
}

void DFS_traverse()
{
    DFS(1);
    for (int i = 1; i <= n; ++i) {
        if (marked[i] == false) {
            res.push_back(false);
            return;
        }
    }
    res.push_back(true);
}

void clear()
{
    for (int i = 1; i < CAPCITY; ++i) {
        marked[i] = false;
        for (int j = 1; j < CAPCITY; ++j)
            graph[i][j] = (i == j ? true : false);
    }
}

int main()
{
    int C1, C2, i;
    while (scanf("%d%d", &n, &m)) {
        if (m == 0 && n == 0)
            break;
        else
            clear();

        for (i = 0; i < m; ++i) {
            scanf("%d%d", &C1, &C2);
            graph[C1][C2] = true;
            graph[C2][C1] = true;
        }
        DFS_traverse();
    }

    for (i = 0; i < res.size(); ++i) {
        if (res[i] == false)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}