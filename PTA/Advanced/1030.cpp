#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define INF 0x3fffffff
struct node {
	int to, edge, cost;
	node(int idx, int edgeval, int cos) : to(idx), edge(edgeval), cost(cos) {}
};
vector<vector<struct node>> citys;
vector<bool> visited;
vector<int> dist, min_cost, path;
int N, M, S, D;

void Dijkstra(int s)
{
	dist[s] = 0;
	for (int i = 0; i < N; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < N; ++j) {
			if (visited[j] == false && dist[j] < min) {
				min = dist[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		visited[u] = 1;
		for (auto it : citys[u]) {
			int v = it.to, edgeval = it.edge, costval = it.cost;
			if (visited[v] == false && edgeval != INF) {
				if ((edgeval + dist[u] < dist[v])
					|| ((edgeval + dist[u] == dist[v]) && (min_cost[v] > min_cost[u] + costval))) {
					dist[v] = edgeval + dist[u];
					path[v] = u;
					min_cost[v] = min_cost[u] + costval;
				}
			}
		}
	}
	path[s] = -1;
}

void print_shortest_path(int d)
{
	int cur = d;
	stack<int> s;
	while (cur != -1) {
		s.push(cur);
		cur = path[cur];
	}
	while (!s.empty()) {
		int topelem = s.top();
		printf("%d ", topelem);
		s.pop();
	}
}

int main()
{
	int c1, c2, dis, cos, i;

	scanf("%d%d%d%d", &N, &M, &S, &D);
	visited.resize(N, false);
	dist.resize(N, INF);
	min_cost.resize(N, 0);
	path.resize(N, -1);
	citys.resize(N);
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d%d", &c1, &c2, &dis, &cos);
		struct node cur1(c2, dis, cos);
		struct node cur2(c1, dis, cos);
		citys[c1].push_back(cur1);
		citys[c2].push_back(cur2);
	}
	Dijkstra(S);
	print_shortest_path(D);
	printf("%d %d", dist[D], min_cost[D]);

	return 0;
}