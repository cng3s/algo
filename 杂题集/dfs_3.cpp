/*
《算法笔记》P276
给出一个m*n的矩阵，矩阵中的元素为0或1。
称位置(x, y)与其上下左右四个位置(x,y+1),(x,y-1),(x-1,y),(x+1,y)是相邻的。
如果矩阵中有若干个1是相邻的（不必要两两相邻），那么称这些1构成了一个“块”。
求矩阵中给定块个数

给出DFS解法

test case:
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0

out: 4
*/
#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;


#define MAXN 100
int xbias[4] = { 0, 0, 1, -1 }, ybias[4] = { 1, -1, 0, 0 };
int m, n;
bool mat[MAXN][MAXN], vis[MAXN][MAXN];

bool is_valid(int x, int y)
{ return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && mat[x][y]); }

void dfs(int x, int y)
{
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int curx = x + xbias[i], cury = y + ybias[i];
		if (is_valid(curx, cury))
			dfs(curx, cury);
	}
}

int main()
{
	int i, j, ans = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			scanf("%d", &mat[i][j]);
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			if (is_valid(i, j)) {
				dfs(i, j);
				++ans;
			}
	}
	printf("%d", ans);

	return 0;
}