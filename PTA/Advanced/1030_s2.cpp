#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define INF 0x3fffffff
#define MAX_CITYS 500
int N, M, S, D, g[MAX_CITYS][MAX_CITYS];
bool visited[MAX_CITYS];
int dist[MAX_CITYS], cost[MAX_CITYS][MAX_CITYS];
int min_cost = INF;
vector<int> pre[MAX_CITYS];
vector<int> tmppath, path;

void Dijkstra(int s)
{
	fill(dist, dist + MAX_CITYS, INF);
	dist[s] = 0;
	for (int i = 0; i < N; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < N; ++j) {
			if (visited[j] == false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (int v = 0; v < N; ++v) {
			if (visited[v] == false && g[u][v] != INF) {
				if (dist[u] + g[u][v] < dist[v]) {
					pre[v].clear();
					pre[v].push_back(u);
					dist[v] = dist[u] + g[u][v];
				} else if (dist[u] + g[u][v] == dist[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int idx)
{
	if (idx == S) {
		tmppath.push_back(idx);
		int tmpcost = 0;
		for (int i = tmppath.size() - 1; i > 0; --i) {
			int curid = tmppath[i], nextid = tmppath[i-1];
			tmpcost += cost[curid][nextid];
		}
		if (tmpcost < min_cost) {
			min_cost = tmpcost;
			path = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	tmppath.push_back(idx);
	for (auto it : pre[idx])
		DFS(it);
	tmppath.pop_back();
}

int main()
{
	int c1, c2, dis, cos, i;

	scanf("%d%d%d%d", &N, &M, &S, &D);
	fill(g[0], g[0] + MAX_CITYS * MAX_CITYS, INF);
	fill(cost[0], cost[0] + MAX_CITYS * MAX_CITYS, INF);
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d%d", &c1, &c2, &dis, &cos);
		g[c1][c2] = g[c2][c1] = dis;
		cost[c1][c2] = cost[c2][c1] = cos;
	}
	Dijkstra(S);
	DFS(D);
	for (int i = path.size() - 1; i >= 0; --i)
		printf("%d ", path[i]);
	printf("%d %d", dist[D], min_cost);

	return 0;
}