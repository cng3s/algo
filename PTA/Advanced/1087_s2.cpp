#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

#define MAXV 201
#define INF 0x3fffffff
struct u {
	int v, e;
	u(int vertex, int edge) : v(vertex), e(edge) {}
};
int N, dst;
map<string, int> city_idx;
map<int, string> idx_city;
vector<struct u> g[MAXV];
int pre[MAXV], dist[MAXV], weight[MAXV], w[MAXV], routes[MAXV], cost[MAXV];
bool vis[MAXV];

void dijkstra(int s)
{
	fill(dist, dist + N, INF);
	dist[s] = 0;
	pre[s] = -1;
	routes[s] = 1;
	for (int i = 0; i < N; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < N; ++j) {
			if (vis[j] == false && min > dist[j]) {
				u = j;
				min = dist[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (auto it : g[u]) {
			int v = it.v, e = it.e;
			if (vis[v] == false) {
				int d = dist[u] + e, vweight = weight[v] + w[u];
				if (d < dist[v]) {
					pre[v] = u;
					cost[v] = cost[u] + 1;
					routes[v] = routes[u];
					dist[v] = d;
					w[v] = vweight;
				} else if (d == dist[v]) {
					routes[v] += routes[u];
					if (vweight > w[v]) {
						w[v] = vweight;
						pre[v] = u;
						cost[v] = cost[u] + 1;
					} else if (vweight == w[v]) {
						double uavg = 1.0 * vweight / (cost[u] + 1)
							, vavg = 1.0 * w[v] / cost[v];
						if (uavg > vavg) {
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
	int K, i, val, c1idx, c2idx;
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
	for (i = 0; i < K; ++i) {
		cin >> c1 >> c2 >> val;
		c1idx = city_idx[c1];
		c2idx = city_idx[c2];
		struct u cur1(c2idx, val);
		struct u cur2(c1idx, val);
		g[c1idx].push_back(cur1);
		g[c2idx].push_back(cur2);
	}

	dijkstra(0);

	printf("%d %d %d %d\n", routes[dst], dist[dst], w[dst], w[dst] / cost[dst]);
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