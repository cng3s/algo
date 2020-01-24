#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXV 1000
#define INF 0x3fffffff
struct edge {
	int u, v, w;
} edges[MAXV];
int roots[MAXV];
vector<pair<int, int>> edge_seq;
int N;

bool cmp(struct edge e1, struct edge e2) { return e1.w < e2.w; }

void ufset_init() { for (int i = 0; i < N; ++i) roots[i] = i; }

int ufset_find_root(int x)
{
	int xroot = x;
	while (xroot != roots[xroot])
		xroot = roots[xroot];
	while (x != roots[x]) {
		int tmp = roots[x];
		roots[x] = xroot;
		x = tmp;
	}
	return xroot;
}

int kruskal(int n, int m)
{
	int ret = 0, edgenum = 0;
	ufset_init();
	sort(edges, edges + m, cmp);
	for (int i = 0; i < m; ++i) {
		int uroot = ufset_find_root(edges[i].u), vroot = ufset_find_root(edges[i].v);
		if (uroot != vroot) {
			roots[uroot] = vroot;
			ret += edges[i].w;
			edgenum += 1;
			edge_seq.push_back(make_pair(edges[i].u, edges[i].v));
			if (edgenum == n - 1) break;
		}
	}
	return edgenum == n - 1 ? ret : -1;
}

int main()
{
	int M, i, u, v, w;
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
	}
	w = kruskal(N, M);
	printf("%d\n", w);
	for (i = 0; i < edge_seq.size(); ++i)
		printf("%d-%d ", edge_seq[i].first, edge_seq[i].second);

	return 0;
}