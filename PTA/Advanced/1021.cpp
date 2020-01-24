/* 基于该图论定理的做法：
	1. 若图连通并边数为N-1，则一定是一棵树
	2. 若是树，要使树高最大，则：
		先任选一结点x出发遍历整棵树，并把能达到最深结点的路径添加到集合A中
		再从tmp中任选一结点y出发，重复上述步骤生成集合B
		A与B并集即为使树高最大的根节点
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NODES 10001
vector<int> g[MAX_NODES];
vector<int> res, tmp;
int roots[MAX_NODES];
bool is_root[MAX_NODES];
int N, max_height;

void ufset_init()
{
	for (int i = 1; i < MAX_NODES; ++i)
		roots[i] = i;
}

int ufset_find_root(int x)
{
	int xroot = x;
	while (roots[xroot] != xroot)
		xroot = roots[xroot];
	while (roots[x] != x) {
		int tmp = roots[x];
		roots[x] = xroot;
		x = tmp;
	}
	return xroot;
}

void ufset_union(int a, int b)
{
	int aroot = ufset_find_root(a)
		, broot = ufset_find_root(b);
	if (aroot != broot)
		roots[broot] = aroot;
}

int cal_clusters(int num_nodes)
{
	int clusters = 0;
	for (int i = 1; i <= num_nodes; ++i)
		is_root[ufset_find_root(i)] = true;
	for (int i = 1; i <= num_nodes; ++i) {
		if (is_root[i] == true)
			clusters += 1;
	}
	return clusters;
}

void DFS(int idx, int height, int preidx)
{
	if (height > max_height) {
		tmp.clear();
		max_height = height;
		tmp.push_back(idx);
	} else if (height == max_height) {
		tmp.push_back(idx);
	}
	for (int i = 0; i < g[idx].size(); ++i) {
		if (g[idx][i] == preidx)
			continue;
		DFS(g[idx][i], height + 1, idx);
	}
}

int main()
{
	int C1, C2;
	scanf("%d", &N);
	ufset_init();
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &C1, &C2);
		g[C1].push_back(C2);
		g[C2].push_back(C1);
		ufset_union(C1, C2);
	}
	int clusters = cal_clusters(N);
	if (clusters != 1) {
		printf("Error: %d components", clusters);
		return 0;
	}
	DFS(1, 1, -1);
	res = tmp;
	DFS(res[0], 1, -1);
	for (int i = 0; i < tmp.size(); ++i)
		res.push_back(tmp[i]);
	sort(res.begin(), res.end());
	printf("%d\n", res[0]);
	for (int i = 1; i < res.size(); ++i) {
		if (res[i] != res[i - 1])
			printf("%d\n", res[i]);
	}

	return 0;
}