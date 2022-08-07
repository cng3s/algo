#pragma warning(disable : 4996)
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;

#define INF 0x3fffffff
vector<vector<pair<int, int>>> g;
vector<bool> visited;
vector<int> dist, path;
int V, from;

void Dijkstra(int s)
{
	visited.resize(V, false);
	dist.resize(V, INF);
	path.resize(V, -1);
	dist[s] = 0;
	from = s;
	for (int i = 0; i < V; ++i) {
		int u = -1, min = INF;
		for (int v = 0; v < V; ++v) {
			if (visited[v] == false && dist[v] < min) {
				u = v;
				min = dist[v];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (int j = 0; j < g[u].size(); ++j) {
			int v = g[u][j].first;
			if (visited[v] == false && g[u][j].second != INF && dist[u] + g[u][j].second < dist[v]) {
				dist[v] = g[u][j].second + dist[u];
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
	printf("from %d -> to %d: %d", from, to, from);
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
		g[C1].push_back(make_pair(C2, Val));
	}
	Dijkstra(0);
	print_shortest_path(1);
	print_shortest_path(2);
	print_shortest_path(3);
	
	for (int i = 0; i < dist.size(); ++i)
		printf("%d: %d\n", i, dist[i]);

	return 0;
}


/*
 test case :
5 10
0 1 10
0 4 5
1 2 1
1 4 2
4 1 3
4 2 9
3 0 7
2 3 4
3 2 6
4 3 2
*/