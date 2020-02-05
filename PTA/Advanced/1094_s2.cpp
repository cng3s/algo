#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 101
vector<int> tree[MAXN];
int n, m, hashtab[MAXN] = { 0 }, maxgen = -1, maxpop = 0;

void bfs(int idx)
{
	int lev;
	queue<pair<int, int>> q;
	q.push({ idx, 1 });
	while (!q.empty()) {
		int curidx = q.front().first, curlev = q.front().second;
		q.pop();
		++hashtab[curlev];
		if (hashtab[curlev] > maxpop) {
			maxpop = hashtab[curlev];
			maxgen = curlev;
		}
		for (auto it : tree[curidx])
			q.push({ it, curlev+1 });
	}
}

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) {
		int j, idx, k, id;
		scanf("%d%d", &idx, &k);
		for (j = 0; j < k; ++j) {
			scanf("%d", &id);
			tree[idx].push_back(id);
		}
	}
	bfs(1);
	printf("%d %d", hashtab[maxgen], maxgen);

	return 0;
}
