#pragma warning(disable : 4996)
#include <set>
#include <stack>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff
struct node {
	int to, edge;
	node(int idx, int val) : to(idx), edge(val) {}
};
bool operator<(const struct node& lhs, const struct node& rhs)
{
	return lhs.to < rhs.to;
}

vector<set<node>> g;
vector<bool> visited;
vector<int> path, dist;
int V, from_idx;

void Dijkstra(int s)
{
	visited.resize(V, false);
	dist.resize(V, INF);
	path.resize(V, -1);
	dist[s] = 0;
	from_idx = s;
	for (int i = 0; i < V; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < V; ++j) {
			if (visited[j] == false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		
		if (u == -1)
			return;
		visited[u] = true;
		for (auto it : g[u]) {
			int v = it.to;
			if (visited[v] == false && it.edge != INF && it.edge + dist[u] < dist[v]) {
				dist[v] = it.edge + dist[u];
				path[v] = u;
			}
		}
	}
	path[s] = -1;
}

void print_shortest_path(int to)
{
	int cur = to;
	stack<int> s;
	printf("from %d -> to %d: %d", from_idx, to, from_idx);
	while (path[cur] != -1) {
		s.push(cur);
		cur = path[cur];
	}
	while (!s.empty()) {
		int top = s.top();
		s.pop();
		printf(" %d", top);
	}
	printf("\n");
}

int main()
{
	int E, C1, C2, Val;
	scanf("%d%d", &V, &E);
	g.resize(V);
	for (int i = 0; i < E; ++i) {
		scanf("%d%d%d", &C1, &C2, &Val);
		struct node cur(C2, Val);
		g[C1].insert(cur); // 比较键值还是比较值？
	}
	Dijkstra(0);
	print_shortest_path(1);
	print_shortest_path(2);
	print_shortest_path(3);
	for (int i = 0; i < dist.size(); ++i)
		printf("%d: %d\n", i, dist[i]);

	return 0;
}