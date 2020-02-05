#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 101
vector<int> tree[MAXN];
int n, m, hashtab[MAXN] = { 0 }, maxgen = -1;

void dfs(int idx, int curlev)
{
	++hashtab[curlev];
	for (auto it : tree[idx])
		dfs(it, curlev+1);
}

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) {
		int j, idx, k, id;
		scanf("%d%d", &idx, &k);
		for (j = 0; j < k; ++j) {
			scanf("%d", &id);
			tree[idx].push_back(id);
		}
	}
	dfs(1, 1);
	for (i = 1; i <= n; ++i) {
		if (hashtab[i] > maxgen)
			maxgen = i;
	}
	printf("%d %d", hashtab[maxgen], maxgen);

	return 0;
}