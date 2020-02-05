#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 100001
struct node { vector<int> childs; } tree[MAXN];
int n, maxlev = 0, maxans_cnt = 0, root;
double p, r, maxans = 0.0;
double tab[MAXN];

void gen_tab(int lev)
{
	for (int i = maxlev+1; i <= lev; ++i)
		tab[i] = tab[i-1] * r;
}

void dfs(int idx, int lev)
{
	if (tree[idx].childs.empty()) {
		if (lev > maxlev) {
			gen_tab(lev);
			maxlev = lev;
		}
		if (tab[lev] > maxans) {
			maxans = tab[lev];
			maxans_cnt = 1;
		} else if (tab[lev] == maxans) {
			++maxans_cnt;
		}
		return;
	}

	for (auto it : tree[idx].childs)
		dfs(it, lev+1);
}

int main()
{
	int i, tmp;
	scanf("%d%lf%lf", &n, &p, &r);
	tab[0] = p;
	r = 1 + 0.01 * r;
	for (i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (tmp == -1)
			root = i;
		else
			tree[tmp].childs.push_back(i);
	}
	dfs(root, 0);
	printf("%.2lf %d", maxans, maxans_cnt);

	return 0;
}