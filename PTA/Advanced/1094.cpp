#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 101
vector<int> tree[MAXN];
int n, m, hashtab[MAXN] = { 0 }, maxgen = -1, maxpop = 0;

void dfs(int idx, int curlev)
{
	/* 这里卡了好久，才发现我把人口数和家庭代数相比较，才无法通过
	无法AC时一定要自己调试，而不是看别人代码。训练思维严谨性。
	作比较时要注意比较的左右两边是否是同一个东西。
	if (hashtab[curlev] > maxgen)
		maxgen = curlev;*/
	++hashtab[curlev];
	if (hashtab[curlev] > maxpop) {
		maxpop = hashtab[curlev];
		maxgen = curlev;
	}
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
	printf("%d %d", hashtab[maxgen], maxgen);

	return 0;
}
