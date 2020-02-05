#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 100001
vector<int> tree[MAXN];
int n, maxlev = 0, min_retailer_lev = 0x3fffffff;
double p, r, min_price;
int min_price_retailers = 0;
double tab[MAXN];

void gen_tab(int lev)
{
	for (int i = maxlev + 1; i <= lev; ++i)
		tab[i] = tab[i-1] * r;
}

void dfs(int idx, int lev)
{
	if (tree[idx].empty()) {
		if (lev < min_retailer_lev)
			min_price_retailers = 1;
		else
			++min_price_retailers;
		min_retailer_lev = lev;
		if (lev > maxlev) {
			gen_tab(lev);
			maxlev = lev;
		}
		min_price = tab[lev];
		return;
	}
	if (lev + 1 <= min_retailer_lev) {
		for (auto it : tree[idx])
			dfs(it, lev + 1);
	}
}

int main()
{
	int i, k, id;
	scanf("%d%lf%lf", &n, &p, &r);
	tab[0] = p;
	r = 1 + r * 0.01;
	for (i = 0; i < n; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &id);
			tree[i].push_back(id);
		}
	}
	dfs(0, 0);
	printf("%.4lf %d", min_price, min_price_retailers);

	return 0;
}