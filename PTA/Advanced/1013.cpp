
#include <cstdio>
#include <queue>
using namespace std;

#define MAX_CITYS 1001

bool citys[MAX_CITYS][MAX_CITYS] = { 0 };
bool visited[MAX_CITYS] = { true };
int cluster = 0;
int N, M, K, need_roads = 0;
queue<int> res;

void DFS(int index)
{
	visited[index] = true;
	queue<int> q;
	q.push(index);

	while (!q.empty()) {
		index = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (citys[index][i] == true && visited[i] == false) {
				visited[i] = true;
				q.push(i);
			}
		}
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
	visited[city] = 1;
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