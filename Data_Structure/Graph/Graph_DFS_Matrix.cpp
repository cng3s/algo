#include <iostream>
#include <climits>
using namespace std;

#define MAXN 1000
#define INF INT_MAX

bool graph[MAXN][MAXN];
bool visited[MAXN];
int N, M;

void DFS(int index)
{
	visited[index] = true;
	cout << index << " ";
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == false && graph[index][i] == true)
			DFS(i);
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
		graph[C1][C2] = graph[C2][C1] = true;
	}
	DFS_traverse();

	return 0;
}