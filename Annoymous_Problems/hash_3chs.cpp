/* ��������N������Ӣ�Ĵ�д�ַ���ɵ��ַ�����������M����Ҫ�жϵ��ַ���str������ַ���str�ĳ��ִ��� */
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
/* �ʼǣ�
	�ó��������tmp[3]���������´���
	Run-Time Check Failure #2 - Stack around the variable 'tmp' was corrupted.
	ԭ������string�����һ��'/0'��ʾ����������û�а�'/0'�ַ��������ڣ���������������
*/