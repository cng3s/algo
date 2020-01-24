// 《算法笔记》P332
/*
【好朋友】
有一个叫做“数码世界”奇异空间，在数码世界里生活着许许多多的数码宝贝，其中有些数码宝贝之间可能是好朋友，并且数码宝贝世界有两条不成文的规定：
第一，数码宝贝A和数码宝贝B是好朋友等价于数码宝贝B与数码宝贝A是好朋友
第二，如果数码宝贝A和数码宝贝C是好朋友，而数码宝贝B和数码宝贝C也是好朋友，那么A和B也是好朋友，现在给出这些数码宝贝中所有好朋友的信息
问：可以把这些数码宝贝分成多少组，满足每组中的任意两个数码宝贝都是好朋友，而且任意两组之间的数码宝贝都不是好朋友。

输入格式：
输入第一行有两个正整数n(<=100)和m(m<=100)，分别表示数码宝贝的个数和好朋友的组数，其中数码宝贝编号为1-n
输出格式：
输出一个整数，表示这些数码宝贝可以分成组数

e.x.
input:
4 2
1 4
2 3
output:
2
input:
7 5
1 3
2 3
3 1
1 4
5 6
output:
3
*/
#include <iostream>
using namespace std;
#define MAXN 101

int roots[MAXN];
int visited[MAXN] = { 0 };
int N, M, res = 0;

inline int ufset_find(int x)
{
	return roots[x];
}

// 使用ufset_insert保证进行路径压缩
void ufset_insert(int x, int xroot)
{
	if (roots[xroot] == x) // 禁止套娃
		return;

	roots[x] = xroot;
	while (roots[xroot] != 0) {
		roots[x] = roots[xroot];
		xroot = roots[xroot];
	}
}

int main()
{
	int C1, C2;
	
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> C1 >> C2;
		ufset_insert(C1, C2);
	}
	for (int i = 0; i < N; ++i) {
		if (roots[i] > 0 && visited[i] == false)
			res += 1;
	}
	cout << res;

	return 0;
}