/*
本题犯的错误：
1. 审题不对，要考虑的是最少发放自行车的数量，而我考虑成点权最大的路径
2. 本题陷阱，要按站点先后顺序发放自行车
 本题陷阱：
 从PBMC到Sp的过程中就要把路径上所有站点调整为最佳状态（即只有一趟遍历的过程）
 所以要考虑站点遍历的先后顺序来确定自行车多或少的数量
*/

#pragma warning(disable : 4996)
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff
struct node {
	int to, edge;
	node(int t, int e) : to(t), edge(e) {}
};
vector<vector<struct node>> g;
vector<bool> visited;
vector<int> dist, station_bikes, cur_bikes;
vector<vector<int>> pre;
int Cmax, Cmid, N, Sp, PBMC_send, PBMC_ret;
vector<int> tmp_path, best_path;
int min_need_bikes = INF, min_remain_bikes = INF;

void Dijkstra(int s)
{
	dist[s] = 0;
	cur_bikes[s] = station_bikes[s];
	for (int i = 0; i <= N; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j <= N; ++j) {
			if (visited[j] == false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (auto it : g[u]) {
			int v = it.to, edgeval = it.edge;
			if (visited[v] == false) {
				if (edgeval + dist[u] < dist[v]) {
					dist[v] = dist[u] + edgeval;
					pre[v].clear();
					pre[v].push_back(u);
				} else if (edgeval + dist[u] == dist[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int cur)
{
	if (cur == 0) {
		tmp_path.push_back(cur);
		int extra = 0, need = 0, remain = 0;
		for (int i = tmp_path.size() - 2; i >= 0; --i) {
			// tmp_path.size() - 2 忽视掉i == 0 即PBMC不参与计算
			int curidx = tmp_path[i];
			extra = station_bikes[curidx] - Cmid;
			if (extra < 0) { // 还需要自行车,尝试使用remain的自行车来补
				extra = abs(extra);
				if (remain > extra) {
					remain -= extra;
				} else {
					need += extra - remain;
					remain = 0;
				}
			} else if (extra > 0) {
				remain += extra;
			}
		}
		if (need < min_need_bikes
			|| (need == min_need_bikes && remain < min_remain_bikes)) {
			best_path = tmp_path;
			min_need_bikes = need;
			min_remain_bikes = remain;
		}

		tmp_path.pop_back();
		return;
	}
	tmp_path.push_back(cur);
	for (auto it : pre[cur])
		DFS(it);
	tmp_path.pop_back();
}


int main()
{
	int M, c1, c2, t, i;
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	Cmid = Cmax / 2;
	g.resize(N + 1);
	station_bikes.resize(N + 1);
	pre.resize(N + 1);
	dist.resize(N + 1, INF);
	visited.resize(N + 1, false);
	cur_bikes.resize(N + 1, 0);
	for (i = 1; i <= N; ++i)
		scanf("%d", &station_bikes[i]);
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d", &c1, &c2, &t);
		struct node cur1(c2, t);
		struct node cur2(c1, t);
		g[c1].push_back(cur1);
		g[c2].push_back(cur2);
	}
	Dijkstra(0);
	DFS(Sp);

	printf("%d ", min_need_bikes);
	for (int i = best_path.size() - 1; i >= 0; --i) {
		printf("%d", best_path[i]);
		if (i != 0)
			printf("->");
	}
	printf(" %d", min_remain_bikes);


	return 0;
}