/*
有n(1<=n<=20)件物品，每件物品的重量为w[i]，价值为c[i]。
现在需要选出若干件物品放入一个容量为V的背包中，使得在选入背包的物品重量和不超过容量v的前提下
让背包中的物品价值之和最大，求最大价值
我们这道题用DFS来做，而不用常规方法做
*/
#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define MAXN 20
int n, v, w[MAXN], c[MAXN], maxc = 0;

void dfs(int idx, int curw, int curc)
{
	/* 剪枝优化 */
	if (idx == n)
		return;
	dfs(idx + 1, curw, curc);
	if (curw + w[idx] <= v) {
		if (curc + c[idx] > maxc)
			maxc = curc + c[idx];
		dfs(idx + 1, curw + w[idx], curc + c[idx]);
	}
}

int main()
{
	int i;
	scanf("%d%d", &n, &v);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &w[i], &c[i]);
	dfs(0, 0, 0);
	printf("%d", maxc);
	return 0;
}

/*
test case:
5 20
20 100
5 20
10 80
6 70
9 90
*/