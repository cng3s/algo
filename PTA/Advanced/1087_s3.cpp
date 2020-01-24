#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAXV 201
#define INF 0x3fffffff
int N, dst, g[MAXV][MAXV], weight[MAXV], num = 0, maxw = -1, avgw;
int dist[MAXV];
vector<int> pre[MAXV], respath, tmppath;
bool vis[MAXV] = { false };
map<string, int> city_idx;
map<int, string> idx_city;


void dijkstra(int s)
{
	fill(dist, dist + N, INF);
	dist[s] = 0;
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
				if (d < dist[v]) {
					dist[v] = d;
					pre[v].clear();
					pre[v].push_back(u);
				} else if (d == dist[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v)
{
	if (v == 0) {
		tmppath.push_back(v);
		int tmpw = 0;
		++num;
		for (int i = tmppath.size() - 2; i >= 0; --i) {
			int id = tmppath[i];
			tmpw += weight[id];
		}
		int tmpavgw = 1.0 * tmpw / (tmppath.size() - 1);
		if (tmpw > maxw) {
			maxw = tmpw;
			avgw = tmpavgw;
			respath = tmppath;
		} else if (tmpw == maxw && tmpavgw > avgw) {
			avgw = tmpavgw;
			respath = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	tmppath.push_back(v);
	for (int i = 0; i < pre[v].size(); ++i)
		DFS(pre[v][i]);
	tmppath.pop_back();
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
	DFS(dst);

	printf("%d %d %d %d\n", num, dist[dst], maxw, maxw / (respath.size() - 1));
	for (i = respath.size() - 1; i >= 0; --i) {
		cout << idx_city[respath[i]];
		if (i != 0)
			printf("->");
	}

	return 0;
}