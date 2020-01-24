#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff
#define MAXV 200
int N, dis[MAXV][MAXV];

void floyd()
{
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) 
				if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	}
}

int main()
{
	int u, v, w, M;
	fill(dis[0], dis[0] + MAXV * MAXV, INF);

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		dis[i][i] = 0;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = w;
	}
	floyd();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			printf("%d ", dis[i][j]);
		printf("\n");
	}

	return 0;
}