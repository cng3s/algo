#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define CAPCITY 100

vector<int> family[CAPCITY];
int res[CAPCITY];
int maxlevel = 0;

void BFS(int root, int level)
{
	if (family[root].size() == 0) {
		res[level] += 1;
		maxlevel = max(level, maxlevel);
		return;
	}

	for (int i = 0; i < family[root].size(); ++i) {
		BFS(family[root][i], level + 1);
	}
}

int main()
{
	int N, M, k;
	int i, j;
	int father, child;

	cin >> N >> M;
	if (N == 0)
		return -1;
	for (i = 0; i < M; ++i) {
		cin >> father >> k;
		for (j = 0; j < k; ++j) {
			cin >> child;
			family[father].push_back(child);
		}
	}

	BFS(1, 0);

	for (i = 0; i <= maxlevel; ++i) {
		cout << res[i];
		if (i + 1 <= maxlevel)
			cout << " ";
	}


	return 0;
}