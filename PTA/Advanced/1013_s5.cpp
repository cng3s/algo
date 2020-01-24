/* 使用并查集解法 */

#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_CITYS 1001
vector<int> citys[MAX_CITYS];
int roots[MAX_CITYS] = { 0 };
bool visited[MAX_CITYS] = { 0 };
int M, N, K, res = -1;

void ufset_init()
{
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		roots[i] = i;
	}
}

int ufset_find_root(int x)
{
	int xroot = x;
	while (roots[xroot] != xroot)
		xroot = roots[xroot];

	while (roots[x] != x) {
		int xfather = roots[x];
		roots[x] = xroot;
		x = xfather;
	}
	return x;
}

void ufset_union(int a, int b)
{
	int aroot = ufset_find_root(a), broot = ufset_find_root(b);
	if (aroot != broot)
		roots[broot] = aroot;
}

int main()
{
	int C1, C2, i;
	scanf("%d%d%d", &N, &M, &K);
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &C1, &C2);
		citys[C1].push_back(C2);
		citys[C2].push_back(C1);
	}
	for (i = 0; i < K; ++i) {
		scanf("%d", &C1);
		ufset_init();
		for (int j = 1; j <= N; ++j) {
			for (int k = 0; k < citys[j].size(); ++k) {
				if (j == C1 || citys[j][k] == C1)
					continue;
				ufset_union(j, citys[j][k]);
			}
		}
		int clusters = 0;
		for (int j = 1; j <= N; ++j) {
			if (j == C1)
				continue;
			int jroot = ufset_find_root(j);
			if (visited[jroot] == false) {
				clusters += 1;
				visited[jroot] = true;
			}
		}
		printf("%d\n", clusters - 1);
	}

	return 0;
}