/* 全排列问题：给一个数N，输入1~N所有可能的排列组合
如：（1，2，3） ===> 123 132 213 231 312 321
*/
#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

int res[100];
bool bit_vis[10];

void full_permutation(int idx, int n)
{
	if (idx == n + 1) {
		for (int i = 1; i <= n; ++i)
			printf("%d", res[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!bit_vis[i]) {
			res[idx] = i;
			bit_vis[i] = true;
			full_permutation(idx + 1, n);
			bit_vis[i] = false;
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	full_permutation(1, N);

	return 0;
}