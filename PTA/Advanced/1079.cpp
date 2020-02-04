#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 100000
struct node { int data; vector<int> childs; node() : data(0) {} } tree[MAXN];
double p, r, ans = 0;
double tab[MAXN];
int n, tablev = 0;

void gen_tab(int lev)
{
	for (int i = tablev + 1; i <= lev; ++i)
		tab[i] = tab[i-1] * r;
}

void dfs(int idx, int curlev)
{
	if (tree[idx].childs.size() == 0) {
		if (curlev > tablev) {
			gen_tab(curlev);
			tablev = curlev;
		}
		ans += tree[idx].data * tab[curlev];
		return;
	}
	for (auto it : tree[idx].childs)
		dfs(it, curlev + 1);
}

int main()
{
	int i, j;
	scanf("%d%lf%lf", &n, &p, &r);
	tab[0] = p;
	r = 1 + r * 0.01;
	for (i = 0; i < n; ++i) {
		int k, id;
		scanf("%d", &k);
		if (k == 0)
			scanf("%d", &tree[i].data);
		for (j = 0; j < k; ++j) {
			scanf("%d", &id);
			tree[i].childs.push_back(id);
		}
	}
	dfs(0, 0);
	printf("%.1lf", ans);

	return 0;
}