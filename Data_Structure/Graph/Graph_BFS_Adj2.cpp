#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1000

struct node {
	int index, layer;
	node(int idx, int lay = 0) : index(idx), layer(0) {}
};
int N, M;
vector<node> graph[MAXN];
bool visited[MAXN];

void BFS(int index)
{
	visited[index] = true;
	struct node start(index, 0);
	queue<node> q;
	q.push(start);

	while (!q.empty()) {
		struct node cur = q.front();
		q.pop();
		int curindex = cur.index;
		cout << cur.index << " " << cur.layer << endl;
		for (int i = 0; i < graph[curindex].size(); ++i) {
			struct node next = graph[curindex][i];
			if (visited[next.index] == false) {
				next.layer = cur.layer + 1; // 这里《算法笔记》可能有错误
				visited[next.index] = true;
				q.push(next);
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
		struct node cur(C2);
		graph[C1].push_back(cur);
	}
	cout << endl << endl;
	BFS_traverse();

	return 0;
}