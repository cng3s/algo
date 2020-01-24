#include <cstdio>
#include <vector>
using namespace std;

#define MAX_CITYS 1001

bool citys[MAX_CITYS][MAX_CITYS];
bool visited[MAX_CITYS];
int cluster = 0, need_roads = 0;

int N, M, K;

void DFS(int index)
{
	visited[index] = true;
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == false && citys[index][i] == 1)
			DFS(i);
	}
}

void DFS_traverse()
{
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == false) {
			DFS(i);
			cluster += 1;
			if (cluster > 1)
				need_roads += 1;
		}
	}
	printf("%d\n", need_roads);
}

void occupy_city(int city)
{
	visited[city] = true;
}

void liberate_citys()
{
	for (int i = 1; i <= N; ++i)
		visited[i] = false;
	need_roads = 0;
	cluster = 0;
}

int main()
{
	int C1, C2;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &C1, &C2);
		citys[C1][C2] = citys[C2][C1] = 1;
	}
	for (int i = 0; i < K; ++i) {
		scanf("%d", &C1);
		occupy_city(C1);
		DFS_traverse();
		liberate_citys();
	}


	return 0;
}