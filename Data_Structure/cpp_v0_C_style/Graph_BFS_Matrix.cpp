#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1000
int N, M;
bool graph[MAXN][MAXN] = { 0 };
bool visited[MAXN];

void BFS(int cur)
{
	queue<int> q;
	visited[cur] = true;
	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < N; ++i) {
			if (visited[i] == false && graph[cur][i] == true) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS_traverse()
{
	for (int i = 0; i < N; ++i) {
		if (visited[i] == false) {
			BFS(i);
		}
	}
}

int main()
{
	int C1, C2;
	cin >> N >> M;


	for (int i = 0; i < M; ++i) {
		cin >> C1 >> C2;
		graph[C1][C2] = true;
	}

	BFS_traverse();

	return 0;
}