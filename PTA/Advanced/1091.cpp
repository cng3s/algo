#pragma warning(disable : 4996)
#include <cstdio>
#include <queue>
using namespace std;

#define MAXL 60
#define MAXM 1286
#define MAXN 128
struct node { int x, y, z; node(int z_, int y_, int x_) : z(z_), y(y_), x(x_) {} };
int M, N, L, T, ans = 0, tmp = 0;
bool mat[MAXL][MAXM][MAXN];
bool isinqueue[MAXL][MAXM][MAXN];
int xbias[6] = { 1, -1, 0, 0, 0 },
	ybias[6] = { 0, 0, 1, -1, 0, 0 },
	zbias[6] = { 0, 0, 0, 0, 1, -1 };

bool is_valid(int z, int y, int x)
{ return (z >= 0 && z < L && y >= 0 && y < M
	&& x >= 0 && x < N && mat[z][y][x] && !isinqueue[z][y][x]); }

void bfs(int z, int y, int x)
{
	queue<node> q;
	struct node cur(z, y, x);
	q.push(cur);
	isinqueue[z][y][x] = true;
	
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int nextx = cur.x + xbias[i],
				nexty = cur.y + ybias[i],
				nextz = cur.z + zbias[i];
			if (is_valid(nextz, nexty, nextx)) {
				//printf("enqueue: %d %d %d\n", nextz, nexty, nextx);
				struct node next(nextz, nexty, nextx);
				isinqueue[nextz][nexty][nextx] = true;
				q.push(next);
				++tmp;
			}
		}
	}
}

int main()
{
	int i, j, k;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for (i = 0; i < L; ++i) {
		for (j = 0; j < M; ++j)
			for (k = 0; k < N; ++k)
				scanf("%d", &mat[i][j][k]);
	}

	for (i = 0; i < L; ++i) {
		for (j = 0; j < M; ++j)
			for (k = 0; k < N; ++k)
				if (is_valid(i, j, k)) {
					tmp = 1;
					bfs(i, j, k);
					if (tmp >= T) ans += tmp;
				}
	}
	printf("%d", ans);

	return 0;
}