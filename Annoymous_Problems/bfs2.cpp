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
#include <queue>
using namespace std;

#define MAXN 1000
int n, m, minsteps = 0x3fffffff;
int sy, sx;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN]; // 这个数组是标记节点是否入队而非节点是否被访问
int xbias[4] = { 1, -1, 0, 0 }, ybias[4] = { 0, 0, 1, -1 };
struct node { int x, y, steps; node(int x_, int y_, int steps_) : x(x_), y(y_), steps(steps_) {} };

bool is_valid(int y, int x)
{ return (x >= 0 && x < m && y >= 0 && y < n && !vis[y][x] && mat[y][x] != '*'); }

void bfs(int x, int y)
{
	queue<node> q;
	q.push(struct node(x, y, 0));
	vis[y][x] = true;
	while (!q.empty()) {
		struct node cur = q.front();
		q.pop();
		if (mat[cur.y][cur.x] == 'T') {
			if (cur.steps < minsteps)
				minsteps = cur.steps;
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nextx = cur.x + xbias[i], nexty = cur.y + ybias[i], nextsteps = cur.steps + 1;
			if (is_valid(nexty, nextx) && nextsteps < minsteps) {
				vis[nexty][nextx] = true;
				q.push(struct node(nextx, nexty, nextsteps));
			}
		}
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
	bfs(sx, sy);
	printf("%d", (minsteps == 0x3fffffff) ? -1 : minsteps);

	return 0;
}