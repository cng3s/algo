#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 1000

vector<int> graph[MAXN];
int N, M;
bool visited[MAXN] = { false };

void BFS(int index)
{
	visited[index] = true;
	queue<int> q;
	q.push(index);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (visited[next] == false) {
				q.push(next);
				visited[next] = true;
			}
		}
	}

}

void BFS_traverse()
{
	for (int i = 0; i < N; ++i) {
		if (visited[i] == false)
			BFS(i);
	}
}

int main()
{
	int C1, C2;

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> C1 >> C2;
		graph[C1].push_back(C2);
	}
	BFS_traverse();

	return 0;
}