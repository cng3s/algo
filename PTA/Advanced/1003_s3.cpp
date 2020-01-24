// 使用最小堆和前向星优化
#pragma warning(disable : 4996)
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXV 501
#define MAXE 500010
#define INF 0x3fffffff
struct edge {
    int to, next, dis;
} edges[MAXE];
int dis[MAXV], weight[MAXV], w[MAXV], num[MAXV];
int head[MAXE], cnt = 0;
bool vis[MAXV];
int N, C1, C2;

void add_edge(int u, int v, int dis)
{
    edges[cnt].to = v;
    edges[cnt].dis = dis;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dis, dis + N, INF);
    dis[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    pq.push({dis[s], s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to, curdis = edges[i].dis + dis[u], curw = w[u] + weight[v];
            if (vis[v] == true) continue;
            if (curdis < dis[v]) {
                num[v] = num[u];
                w[v] = curw;
                dis[v] = curdis;
                pq.push({ curdis, v });
            } else if (curdis == dis[v]) {
                num[v] += num[u];
                w[v] = max(curw, w[v]);
            }
        }
    }
}

int main()
{
    int c1, c2, l, M, i;
    fill(head, head + MAXV, -1);
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for (i = 0; i < N; ++i)
        scanf("%d", &weight[i]);
    for (i = 0; i < M; ++i) {
        scanf("%d%d%d", &c1, &c2, &l);
        add_edge(c1, c2, l);
        add_edge(c2, c1, l);
    }
    dijkstra(C1);
    printf("%d %d", num[C2], w[C2]);

    return 0;
}