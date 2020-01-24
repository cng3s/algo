// 使用bellman-ford算法
#pragma warning(disable : 4996)
#include <set>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXV 500
#define INF 0X3fffffff
struct node {
	int v, dis;
	node(int v_, int dis_) : v(v_), dis(dis_) {}
};
vector<node> g[MAXV];
set<int> pre[MAXV];
int dist[MAXV], w[MAXV], num[MAXV], weight[MAXV];
int N, C1, C2;

void bellman(int s)
{
	fill(dist, dist + MAXV, INF);
	dist[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
	for (int i = 0; i < N; ++i) {
		for (int u = 0; u < N; ++u) {
			for (int j = 0; j < g[u].size(); ++j) {
				int v = g[u][j].v, dis = g[u][j].dis;
				int d = dis + dist[u];
				if (d < dist[v]) {
					dist[v] = d;
					pre[v].clear();
					pre[v].insert(u);
					num[v] = num[u];
				} else if (d == dist[v]) {
					int vw = weight[v] + w[u];
					if (vw > w[v])
						w[v] = vw;
					pre[v].insert(u);
					num[v] = 0;
					for (auto it : pre[v])
						num[v] += num[it];
				}
			}
		}
	}

}

int main()
{
	int M, l, i, c1, c2;
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for (i = 0; i < N; ++i)
		scanf("%d", &weight[i]);
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d", &c1, &c2, &l);
		struct node cur1(c2, l);
		struct node cur2(c1, l);
		g[c1].push_back(cur1);
		g[c2].push_back(cur2);
	}
	bellman(C1);
	printf("%d %d", num[C2], w[C2]);

	return 0;
}