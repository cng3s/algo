#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXV 1000
#define INF 0x3fffffff
vector<int> g[MAXV];
int indegree[MAXV];
int N, m;

bool topological_sort()
{
	int vertexnum = 0;
	queue<int> q;
	for (int i = 0; i < N; ++i) { 
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		printf("%d ", u);
		q.pop();
		for (auto it : g[u]) {
			if ((--indegree[it]) == 0)
				q.push(it);
		}
		g[u].clear();
		++vertexnum;
	}
	printf("\n");
	return vertexnum == N ? true : false;
}

int main()
{
	int M, i, u, v;
	bool res;
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		++indegree[v];
	}
	res = topological_sort();
	printf("%d\n", res);

	return 0;
}