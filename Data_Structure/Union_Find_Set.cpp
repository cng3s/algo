#include <iostream>
using namespace std;

#define MAXN 1000
int roots[MAXN];
int N, M;

void init()
{
	for (int i = 0; i < N; ++i)
		roots[i] = i;
}

int find(int x)
{
	while (roots[x] != x)
		x = roots[x];
	return x;
}

int find_recursion(int x)
{
	return roots[x] == x ? x : find_recursion(roots[x]);
}

void union_set(int a, int b)
{
	int aroot = find(a), broot = find_recursion(b);
	if (aroot != broot)
		roots[broot] = aroot;
}

int compress_path(int x)
{
	int xroot = find(x), xfather;

	while (xroot != x) {
		xfather = roots[x];
		roots[x] = xroot;
		x = xfather;
	}
	return xroot;
}

int main()
{
	int C1, C2;
	cin >> N >> M;

	init();
	for (int i = 0; i < M; ++i) {
		cin >> C1 >> C2;
		roots[C1] = C2;
	}

	for (int i = 0; i < N; ++i) {
		cout << find(i) << " ";
		compress_path(i);
	}
	cout << endl;
	for (int i = 0; i < N; ++i) {
		cout << find(i) << " ";
	}



	return 0;
}