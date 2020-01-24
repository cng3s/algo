#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAXN 1001
#define INF INT_MAX

vector<int> graph[MAXN];
bool visited[MAXN];
int N, M;

void DFS(int index)
{
	visited[index] = true;
	cout << index << " ";

	for (int i = 0; i < graph[index].size(); ++i) {
		int cur = graph[index][i];
		if (visited[cur] == false)
			DFS(cur);
	}
}

void DFS_traverse()
{
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == false)
			DFS(i);
	}
}

int main()
{
	int C1, C2;

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> C1 >> C2;
		graph[C1].push_back(C2);
		graph[C2].push_back(C1);
	}
	DFS_traverse();

	return 0;
}