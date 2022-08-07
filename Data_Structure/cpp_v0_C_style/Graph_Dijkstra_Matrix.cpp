#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

#define MAX_POINTS 1000
#define INF 0X3fffffff

int g[MAX_POINTS][MAX_POINTS];
int V, d[MAX_POINTS], path[MAX_POINTS];
bool visited[MAX_POINTS];
int from; // Dijstra执行后的源点索引

void Dijkstra(int s)
{
	fill(d, d + V, INF);
	fill(visited, visited + V, false);
	fill(path, path + V, -1);
	d[s] = 0;
	from = s;
	for (int i = 0; i < V; ++i) {
		int u = -1, min = INF;
		for (int j = 0; j < V; ++j) {
			if (visited[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}

		if (u == -1)
			return;
		visited[u] = true;
		for (int j = 0; j < V; ++j) {
			if (visited[j] == false && g[u][j] != INF && d[u] + g[u][j] < d[j]) {
				d[j] = g[u][j] + d[u];
				path[j] = u;
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
	int M, C1, C2, val;
	scanf("%d%d", &V, &M);
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j)
			g[i][j] = INF;
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &C1, &C2, &val);
		g[C1][C2] = val;
	}
	Dijkstra(0);
	print_shortest_path(1);
	print_shortest_path(2);
	print_shortest_path(3);

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