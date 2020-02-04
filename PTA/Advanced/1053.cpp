#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define MAXN 101
struct node { int w; set<int> childs; } tree[MAXN];
int N, M, S;
vector<vector<int>> res;
vector<int> tmp;

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	for (int i = 0, j = 0; i < v1.size() && j < v2.size(); ++i, ++j) {
		if (v1[i] == v2[j]) continue;
		return v1[i] > v2[j];
	}
	return v1.size() > v2.size();
}

void dfs(int idx, int sum)
{
	sum += tree[idx].w;
	if (tree[idx].childs.empty() && sum == S) {
		tmp.push_back(tree[idx].w);
		vector<int> cur = tmp;
		res.push_back(cur);
		tmp.pop_back();
		return;
	}
	if (sum > S)
		return;
	tmp.push_back(tree[idx].w);
	for (auto it : tree[idx].childs)
		dfs(it, sum);
	tmp.pop_back();
}

int main()
{
	int i, j;
	scanf("%d%d%d", &N, &M, &S);
	for (i = 0; i < N; ++i)
		scanf("%d", &tree[i].w);
	for (i = 0; i < M; ++i) {
		int tmp, idx, num;
		scanf("%d%d", &idx, &num);
		for (j = 0; j < num; ++j) {
			scanf("%d", &tmp);
			tree[idx].childs.insert(tmp);
		}
	}
	dfs(0, 0);
	sort(res.begin(), res.end(), cmp);
	for (auto vec : res) {
		printf("%d", vec[0]);
		for (int i = 1; i < vec.size(); ++i)
			printf(" %d", vec[i]);
		printf("\n");
	}

	return 0;
}