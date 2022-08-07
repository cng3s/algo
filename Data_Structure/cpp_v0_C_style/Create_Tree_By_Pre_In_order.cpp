/*
使用先序遍历和中序遍历序列构建二叉树

test case:
4 2 1 3 8 7 6 9
1 2 3 4 6 7 8 9

out:
1 2 3 4 6 7 8 9
*/
#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define MAX_NODES 100
struct tree { struct tree* l, * r; int data; tree(int e) : l(nullptr), r(nullptr), data(e) {} };
int pre[MAX_NODES], in[MAX_NODES];

struct tree* create_tree(int prel, int prer, int inl, int inr)
{
	if (prel > prer)
		return nullptr;
	struct tree* cur = new tree(pre[prel]);
	int inidx, leftnum;
	for (inidx = inl; inidx <= inr; ++inidx) {
		if (in[inidx] == pre[prel])
			break;
	}
	leftnum = inidx - inl;
	cur->l = create_tree(prel + 1, prel + leftnum, inl, inidx - 1);
	cur->r = create_tree(prel + leftnum + 1, prer, inidx + 1, inr);
	return cur;
}

void traverse_tree(struct tree* root)
{
	printf("%d ", root->data);
	if (root->l)
		traverse_tree(root->l);
	if (root->r)
		traverse_tree(root->r);
}

int main()
{
	int n, i;
	struct tree* root;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &pre[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	root = create_tree(0, n-1, 0, n-1);
	traverse_tree(root);

	return 0;
}