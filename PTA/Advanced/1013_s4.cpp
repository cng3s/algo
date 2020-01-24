// 用scanf才不会超时。。。
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_CITYS 1001

vector<int> citys[MAX_CITYS];
bool visited[MAX_CITYS];
int cluster = 0, need_roads = 0, occupied_city;

int N, M, K;

void DFS(int index)
{
	visited[index] = true;
	for (int i = 0; i < citys[index].size(); ++i) {
		int curcity = citys[index][i];
		if (visited[curcity] == false)
			DFS(curcity);
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

inline void occupy_city(int city)
{
	visited[city] = true;
	occupied_city = city;
}

inline void liberate_citys()
{
	memset(visited, false, sizeof(visited));
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
	for (int i = 0; i < K; ++i) {
		scanf("%d", &C1);
		occupy_city(C1);
		DFS_traverse();
		liberate_citys();
	}

	return 0;
}