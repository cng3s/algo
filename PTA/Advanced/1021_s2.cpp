#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

#define MAX_NODES 10001
vector<int> g[MAX_NODES];
set<int> res;
vector<int> tmp;
bool visited[MAX_NODES];
int N, max_height = 0;

void DFS(int idx, int height)
{
	visited[idx] = true;
	if (height > max_height) {
		tmp.clear();
		tmp.push_back(idx);
		max_height = height;
	} else if (height == max_height) {
		tmp.push_back(idx);
	}
	for (auto it : g[idx]) {
		if (visited[it] == false)
			DFS(it, height + 1);
	}
}

int main()
{
	int C1, C2, cnt = 0, tmp0;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &C1, &C2);
		g[C1].push_back(C2);
		g[C2].push_back(C1);
	}
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == false) {
			DFS(i, 1);
			if (i == 1) {
				if (tmp.size() != 0)
					tmp0 = tmp[0];
				for (auto it : tmp)
					res.insert(it);
			}
			cnt += 1;
		}
	}
	if (cnt != 1) {
		printf("Error: %d components", cnt);
		return 0;
	}
	fill(visited, visited + MAX_NODES, false);
	max_height = 0;
	tmp.clear();
	DFS(tmp0, 1);
	for (auto it : tmp)
		res.insert(it);
	for (auto it : res)
		printf("%d\n", it);

	return 0;
}