/* 假设输入N个三个英文大写字符组成的字符串，再输入M个需要判断的字符串str，输出字符串str的出现次数 */
/*
#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define MAXN 1000
int hash_tab[20000];

int hash_str(char str[], int len)
{
	int ret = 0;
	for (int i = 0; i < len; ++i)
		ret += ret * 26 + (str[i] - 'A');
	return ret;
}

int main()
{
	int N, M, hash;
	char tmp[4];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", tmp);
		hash = hash_str(tmp, 3);
		++hash_tab[hash];
	}
	for (int i = 0; i < M; ++i) {
		scanf("%s", tmp);
		hash = hash_str(tmp, 3);
		printf("%d\n", hash_tab[hash]);
	}

	return 0;
}
*/
/* 笔记：
	该程序如果是tmp[3]则会出现以下错误：
	Run-Time Check Failure #2 - Stack around the variable 'tmp' was corrupted.
	原因在于string最后有一个'/0'表示结束，但你没有把'/0'字符计算在内，造成数组溢出错误。
*/