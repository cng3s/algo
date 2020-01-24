// 手工实现前向星和堆
// test case 4过不去，效率稍高于s3，很可能是堆实现的问题
// 这题中发现原来不用vector而使用数组空间效率提升很大。
#pragma warning(disable : 4996)
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXV 500
#define MAXE 500010
#define INF 0x3fffffff
struct edge {
    int v, next, dis;
} edges[MAXE];
pair<int, int> heap[MAXV];
int dis[MAXV], weight[MAXV], w[MAXV], num[MAXV];
int head[MAXE], cnt = 0, heap_sz = 0;
int N, C1, C2;
bool vis[MAXV];

void add_edge(int u, int v, int dis)
{
    edges[cnt].v = v;
    edges[cnt].dis = dis;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

void adjust_down(int lo, int hi)
{
    int i = lo, j = i * 2;
    while (j <= hi) {
        if (j + 1 <= hi && heap[j+1].first > heap[j].first)
            j = j + 1;
        if (heap[i].first <= heap[j].first) break;
        swap(heap[i], heap[j]);
        i = j;
        j = j * 2;
    }
}

void adjust_up(int lo, int hi)
{
    int i = hi, j = i / 2;
	while (j >= lo) {
		if (heap[i].first >= heap[j].first) break;
		swap(heap[i], heap[j]);
		i = j;
		j = j / 2;
	}
}

void heap_insert(pair<int, int> x)
{
    heap[++heap_sz] = x;
	adjust_up(1, heap_sz);
}

void heap_deltop()
{
    heap[1] = heap[heap_sz--];
	adjust_down(1, heap_sz);
}

void dijkstra(int s)
{
    fill(dis, dis + N, INF);
    dis[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
	heap_insert({dis[s], s});
    while (heap_sz > 0) {
        int u = heap[1].second;
        heap_deltop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v;
            if (vis[v]) continue;
            int curdis = edges[i].dis + dis[u], curw = weight[v] + w[u];
            if (dis[v] > curdis) {
                dis[v] = curdis;
                num[v] = num[u];
                w[v] = curw;
                heap_insert({ curdis, v });
            } else if (dis[v] == curdis) {
                num[v] += num[u];
                w[v] = max(w[v], curw);
            }
        }
    }
}

int main()
{
    int c1, c2, l, M, i;
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    fill(head, head + N, -1);
    // edges.resize(N * N); // Waring: 如果edges用vector则内存消耗比数组还大得多得多。
    // 一些test case数组只有500KB而vector可达到3000KB以上
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