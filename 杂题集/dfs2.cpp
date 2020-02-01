/*
《算法笔记》P278~279
迷宫 n*m, *-墙壁, .-平地, S-起点, T-终点
给出S(x, y), 且只能上下左右移动，求S——>T的最少步数

DFS实现

test case:

5 5
. . . . .
. * . * .
. * S * .
. * * * .
. . . T *

out: 11
*/
#pragma warning(disable : 4996)
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 1000
int n, m, minsteps = 0x3fffffff;
int sy, sx;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int xbias[4] = { 1, -1, 0, 0 }, ybias[4] = { 0, 0, 1, -1 };

bool is_valid(int y, int x)
{ return (x >= 0 && x < n && y >= 0 && y < m && !vis[y][x] && mat[y][x] != '*'); }

void dfs(int x, int y, int cursteps)
{
	vis[y][x] = true;
	if (mat[y][x] == 'T') {
		if (cursteps < minsteps)
			minsteps = cursteps;
	}
	for (int i = 0; i < 4; ++i) {
		int curx = x + xbias[i], cury = y + ybias[i];
		if (is_valid(cury, curx) && cursteps + 1 < minsteps)
			dfs(curx, cury, cursteps + 1);
	}
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 'S') {
				sy = i;
				sx = j;
			}
		}
	}
	dfs(sx, sy, 0);
	printf("%d", (minsteps == 0x3fffffff) ? -1 : minsteps);

	return 0;
}