#pragma warning(disable : 4996)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 11
struct node { int e, l, r, father; node() : e(-1), l(-1), r(-1), father(-1) {} } tree[MAXN];
int n;
vector<int> lev, in;

void invert(int idx)
{
	if (idx < 0 || idx >= n || tree[idx].e == -1)
		return;
	int tmp = tree[idx].l;
	tree[idx].l = tree[idx].r;
	tree[idx].r = tmp;
	invert(tree[idx].l);
	invert(tree[idx].r);
}

void lev_traverse(int root)
{
	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		lev.push_back(cur);
		if (tree[cur].l != -1)
			q.push(tree[cur].l);
		if (tree[cur].r != -1)
			q.push(tree[cur].r);
	}
}

void in_traverse(int idx)
{
	if (tree[idx].l != -1)
		in_traverse(tree[idx].l);
	in.push_back(idx);
	if (tree[idx].r != -1)
		in_traverse(tree[idx].r);
}

int find_root()
{
	for (int i = 0; i < n; ++i) {
		if (tree[i].e != -1 && tree[i].father == -1)
			return i;
	}
	return -1;
}

int main()
{
	int i, tmp, root;
	char l, r;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		//scanf_s("%c%c", &l, &r);
		cin >> l >> r;
		tree[i].e = i;
		if (l != '-') {
			tmp = int(l - '0');
			tree[i].l = tmp;
			tree[tmp].father = i;
		}
		if (r != '-') {
			tmp = int(r - '0');
			tree[i].r = tmp;
			tree[tmp].father = i;
		}
	}

	root = find_root();
	invert(root);
	lev_traverse(root);
	in_traverse(root);
	
	printf("%d", lev[0]);
	for (i = 1; i < n; ++i)
		printf(" %d", lev[i]);
	printf("\n%d", in[0]);
	for (i = 1; i < n; ++i)
		printf(" %d", in[i]);
	
	return 0;
}