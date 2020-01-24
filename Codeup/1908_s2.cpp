/* 优化：矩阵压缩graph数组 */

#pragma warning(disable : 4996)
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

#define CAPCITY 501002
#define INF INT_MAX
int n, m;
vector<bool> graph;
vector<bool> marked;
vector<bool> res;

inline int covert(int i, int j)
{
    return i >= j ? ((i * (i - 1) / 2) + j - 1)
                  : ((j * (j - 1) / 2) + i - 1);
}

inline bool get_graph_ij(int i, int j)
{
    return graph[covert(i, j)];
}

inline void set_graph_ij(int i, int j, bool elem)
{
    graph[covert(i, j)] = elem;
}

void DFS(int index)
{
    marked[index] = true;
    for (int i = 1; i <= n; ++i) {
        if (get_graph_ij(index, i) != false && marked[i] == false)
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
    for (int i = 1; i <= n; ++i) {
        marked[i] = false;
        for (int j = 1; j <= n; ++j)
            set_graph_ij(i, j, (i == j ? true : false));
    }
}

int main()
{
    int C1, C2, i;

    graph.resize(CAPCITY);
    marked.resize(CAPCITY);
    while (scanf("%d%d", &n, &m)) {
        if (m == 0 && n == 0)
            break;
        else
            clear();

        for (i = 0; i < m; ++i) {
            scanf("%d%d", &C1, &C2);
            set_graph_ij(C1, C2, true);
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