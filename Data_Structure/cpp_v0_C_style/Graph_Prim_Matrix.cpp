#pragma warning(disable : 4996)
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define MAXV 1000
#define INF 0x3fffffff
int g[MAXV][MAXV], pre[MAXV], dis[MAXV];
int N;
bool vis[MAXV];
vector<int> respath;

int prim(int s)
{
	fill(pre, pre + MAXV, -1);
	fill(dis, dis + MAXV, INF);
	dis[s] = 0;
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < N; ++j) {
			if (vis[j] == false && min > dis[j]) {
				u = j;
				min = dis[j];
			}
		}
		if (u == -1) return -1;
		vis[u] = true;
		ret += dis[u];
		respath.push_back(u);
		for (int v = 0; v < N; ++v) {
			if (vis[v] == false && g[u][v] != INF && g[u][v] < dis[v]) {
				pre[v] = u;
				dis[v] = g[u][v];
			}
		}
	}
	return ret;
}

void print_shortest_path(int d)
{
	int cur = d;
	printf("0->%d: ", d);
	stack<int> s;
	while (d != -1) {
		s.push(d);
		d = pre[d];
	}
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");
}

int main()
{
	int M, i, u, v, w;
	scanf("%d%d", &N, &M);
	fill(g[0], g[0] + MAXV * MAXV, INF);
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	w = prim(0);
	printf("%d\n", w);
	for (i = 1; i < N; ++i)
		print_shortest_path(i);
	for (i = 0; i < respath.size(); ++i)
		printf("%d ", respath[i]);
	return 0;
}

/*
test case:
6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3


*/