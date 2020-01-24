#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
	vector<int> roots;

public:
	void ufset_init(int n)
	{
		for (int i = 0; i < n; ++i)
			roots[i] = i;
	}

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

	void ufset_union(int a, int b)
	{
		int aroot = ufset_find_root(a), broot = ufset_find_root(b);
		if (aroot != broot)
			roots[aroot] = broot;
	}

public:
	int makeConnected(int n, vector<vector<int>>& connections)
	{
		vector<bool> is_root(n, 0);
		int clusters = 0;
		roots.resize(n);
		ufset_init(n);
		for (auto it : connections)
			ufset_union(it[0], it[1]);
		for (int i = 0; i < n; ++i)
			is_root[ufset_find_root(i)] = true;
		for (int i = 0; i < n; ++i)
			clusters += is_root[i];
		if (connections.size() < n - 1)
			return -1;
		return clusters - 1;
	}
};


int main()
{
	vector<vector<int>> connections = {
		{0, 1}, {0, 2}, {0, 3}, {1, 2} };
	Solution solu;
	int res = solu.makeConnected(6, connections);
	printf("%d", res);

	return 0;
}