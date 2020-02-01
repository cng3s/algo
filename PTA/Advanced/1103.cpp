#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

int n, k, p, maxsum = -1;
vector<int> res, tmp, tab;

void init_tab()
{
	int num = 0, i = 0;
	while (num <= n) {
		tab.push_back(num);
		num = pow(++i, p);
	}
}

/*
两个优化：
1.剪枝if (cnt > k || powsum > n) return
2.从后向前dfs遍历
两个个易错点：
1. 容易写出三个dfs遍历分支，即
dfs(powsum, num - 1, cnt, sum);
tmp.push_bach(num);
dfs(powsum, num, cnt + 1, sum + num);
dfs(powsum, num - 1, cnt + 1, sum + num);
tmp.pop_back();
其实第三个分支是冗余的dfs，会导致超时
2. 如果写成
if (num >= 1) {
	dfs(powsum, num - 1, cnt, sum);
	powsum += tab[num];
	tmp.push_back(num);
	dfs(powsum, num, cnt + 1, sum + num);
	tmp.pop_back();
}
有一个case会无法通过。为什么呢？

*/
void dfs(int powsum, int num, int cnt, int sum)
{
	if (powsum == n && cnt == k) {
		if (sum > maxsum) {
			maxsum = sum;
			res = tmp;
		}
		return;
	}
	if (powsum > n || cnt + 1 > k)
		return;
	if (num >= 1) {
		tmp.push_back(num);
		dfs(powsum + tab[num], num, cnt + 1, sum + num);
		tmp.pop_back();
		dfs(powsum, num - 1, cnt, sum);
	}
}

int main()
{
	scanf("%d%d%d", &n, &k, &p);

	init_tab();
	dfs(0, tab.size() - 1, 0, 0);

	if (maxsum == -1) {
		printf("Impossible");
	} else {
		printf("%d = %d^%d", n, res[0], p);
		for (size_t i = 1; i < res.size(); ++i)
			printf(" + %d^%d", res[i], p);
	}

	return 0;
}