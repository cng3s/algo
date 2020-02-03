/*
给定N个整数（可能有负数），从中选择K个数，使得这K个数之和恰好等于一个给定的整数X
如果有多种方案，选择它们中元素平方和最大的一个，数据保证这样的方案唯一

例如：
从4个整数{2，3，3，4}中选择2个数，使它们和为6，有{2，4}，{3，3}
其中平方和最大的方案为{2，4}
*/
#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, x, maxsqrt = -1, maxsum = -1;
vector<int> res, nums, tmp;

void dfs(int idx, int curk, int cursum, int cursqrt)
{
	// 带剪枝优化的dfs
	if (curk == k && cursum == x) {
		if (cursqrt > maxsqrt) {
			res = tmp;
			maxsqrt = cursqrt;
		}
		return;
	}
	if (idx == n || curk > k || cursum > x || curk + (n - idx) < k)
		return;
	if (curk + (n - idx) - 1 >= k)
		dfs(idx + 1, curk, cursum, cursqrt);
	tmp.push_back(nums[idx]);
	dfs(idx + 1, curk + 1, cursum + nums[idx], cursqrt + pow(nums[idx], 2));
	tmp.pop_back();
}

int main()
{
	int i;
	scanf("%d%d%d", &n, &k, &x);
	nums.resize(n);
	for (i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	dfs(0, 0, 0, 0);
	for (auto it : res)
		printf("%d ", it);

	return 0;
}