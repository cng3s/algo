#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

#define MAXV 201
#define INF 0x3fffffff
int N, dst, g[MAXV][MAXV], weight[MAXV];
int dist[MAXV], w[MAXV], num[MAXV], cost[MAXV], pre[MAXV];
bool vis[MAXV] = { false };
map<string, int> city_idx;
map<int, string> idx_city;

void dijkstra(int s)
{
	fill(dist, dist + N, INF);
	fill(w, w + N, 0);
	fill(cost, cost + N, 0);
	dist[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	pre[s] = -1;
	for (int i = 0; i < N; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < N; ++j) {
			if (vis[j] == false && dist[j] < min) {
				min = dist[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < N; ++v) {
			if (vis[v] == false && g[u][v] != INF) {
				int d = dist[u] + g[u][v];
				int vweight = weight[v] + w[u];
				if (d < dist[v]) {
					dist[v] = d;
					pre[v] = u;
					cost[v] = cost[u] + 1;
					w[v] = vweight;
					num[v] = num[u];
				} else if (d == dist[v]) {
					num[v] += num[u];
					if (vweight > w[v]) {
						pre[v] = u;
						cost[v] = cost[u] + 1;
						w[v] = vweight;
					} else if (vweight == w[v]) {
						int cur_aver = 1.0 * vweight / (cost[u] + 1)
							, pre_aver = 1.0 * w[v] / cost[v];
						if (cur_aver > pre_aver) {
							pre[v] = u;
							cost[v] = cost[u] + 1;
						}
					}
				}
			}
		}
	}
}

int main()
{
	int K, val, i, idx1, idx2;
	string c1, c2;
	cin >> N >> K >> c1;
	city_idx[c1] = 0;
	idx_city[0] = c1;
	for (i = 1; i < N; ++i) {
		cin >> c1 >> val;
		city_idx[c1] = i;
		idx_city[i] = c1;
		weight[i] = val;
	}
	dst = city_idx["ROM"];
	fill(g[0], g[0] + MAXV * MAXV, INF);
	for (i = 0; i < K; ++i) {
		cin >> c1 >> c2 >> val;
		idx1 = city_idx[c1];
		idx2 = city_idx[c2];
		g[idx1][idx2] = g[idx2][idx1] = val;
	}
	
	dijkstra(0);

	printf("%d %d %d %d\n", num[dst], dist[dst], w[dst], w[dst] / cost[dst]);
	stack<int> s;
	while (dst != -1) {
		s.push(dst);
		dst = pre[dst];
	}
	while (!s.empty()) {
		cout << idx_city[s.top()];
		s.pop();
		if (s.size() != 0)
			printf("->");
	}

	return 0;
}