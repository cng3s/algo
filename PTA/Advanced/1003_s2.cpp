#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_CITYS 500
#define INF 0x3fffffff
int g[MAX_CITYS][MAX_CITYS], city_teams[MAX_CITYS];
int dist[MAX_CITYS], teams[MAX_CITYS], num_paths[MAX_CITYS];
bool visited[MAX_CITYS];
int N, C1, C2;

void Dijkstra(int s)
{
	fill(visited, visited + N, false);
	fill(dist, dist + N, INF);
	fill(num_paths, num_paths + N, 0);
	fill(teams, teams + N, 0);
	dist[s] = 0;
	num_paths[s] = 1;
	teams[s] = city_teams[s];

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
		for (int j = 0; j < N; ++j) {
			if (visited[j] == false && g[u][j] != INF) {
				if (dist[u] + g[u][j] < dist[j]) {
					num_paths[j] = num_paths[u];
					dist[j] = dist[u] + g[u][j];
					teams[j] = teams[u] + city_teams[j];
				} else if (dist[u] + g[u][j] == dist[j]) {
					if (teams[j] < teams[u] + city_teams[j])
						teams[j] = teams[u] + city_teams[j];
					num_paths[j] += num_paths[u];
				}
			}
		}
	}
}

int main()
{
	int c1, c2, M, l;
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; ++i)
		scanf("%d", &city_teams[i]);
	fill(g[0], g[0] + MAX_CITYS * MAX_CITYS, INF);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &c1, &c2, &l);
		g[c1][c2] = g[c2][c1] = l;
	}
	Dijkstra(C1);
	printf("%d %d", num_paths[C2], teams[C2]);

	return 0;
}