#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

#define MAXV 201
#define INF 0x3fffffff
struct u {
	int v, e;
	u(int node, int edge) : v(node), e(edge) {}
};
int N, dst, weight[MAXV], num = 0, maxw = -1, avgw;
set<struct u> g[MAXV];
int dist[MAXV];
vector<int> pre[MAXV], respath, tmppath;
bool vis[MAXV] = { false };
map<string, int> city_idx;
map<int, string> idx_city;

bool operator<(const struct u& entry1, const struct u& entry2)
{ return entry1.v < entry2.v; }

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
		for (auto it : g[u]) {
			int v = it.v, e = it.e;
			if (vis[v] == false) {
				int d = e + dist[u];
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
	for (i = 0; i < K; ++i) {
		cin >> c1 >> c2 >> val;
		idx1 = city_idx[c1];
		idx2 = city_idx[c2];
		struct u cur1(idx2, val);
		struct u cur2(idx1, val);
		g[idx1].insert(cur1);
		g[idx2].insert(cur2);
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