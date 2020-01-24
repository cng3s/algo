// 邻接表法和邻接矩阵法在此例中的对比
// 邻接表法在一些case下表现比邻接矩阵好得多
// 但在大数据多元素的情境下表现比邻接矩阵差得多
// 邻接矩阵在各个case下表现平均。
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX_CITYS 1001

vector<int> citys[MAX_CITYS];
bool visited[MAX_CITYS] = { true };
int cluster = 0;
int N, M, K, need_roads = 0;

void DFS(int index)
{
	visited[index] = true;
	queue<int> q;
	q.push(index);

	while (!q.empty()) {
		index = q.front();
		q.pop();
		for (int i = 0; i < citys[index].size(); ++i) {
			int cur = citys[index][i];
			if (visited[cur] == false) {
				visited[cur] = true;
				q.push(cur);
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
		citys[C1].push_back(C2);
		citys[C2].push_back(C1);
	}
	for (int i = 0; i < K; ++i, need_roads = 0) {
		scanf("%d", &C1);
		occupy_city(C1);
		DFS_traverse();
		liberate_citys();
	}

	return 0;
}