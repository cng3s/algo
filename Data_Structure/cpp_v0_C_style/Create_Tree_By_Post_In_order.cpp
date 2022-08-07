/*
通过中序和后序遍历构造一棵树

test case:
1 3 2 6 7 9 8 4
1 2 3 4 6 7 8 9

out: 4 2 1 3 8 7 6 9
*/

#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define MAX_NODES 100
struct tree { struct tree* l, * r; int data; tree(int e) : l(nullptr), r(nullptr), data(e) {} };
int post[MAX_NODES], in[MAX_NODES];

struct tree* create_tree(int postl, int postr, int inl, int inr)
{
	if (postl > postr)
		return nullptr;
	int inidx, rightnum;
	for (inidx = inl; inidx <= inr; ++inidx) {
		if (in[inidx] == post[postr])
			break;
	}
	rightnum = inr - inidx;
	struct tree* cur = new tree(post[postr]);
	cur->r = create_tree(postr - rightnum, postr - 1, inidx + 1, inr);
	cur->l = create_tree(postl, postr - rightnum - 1, inl, inidx - 1);
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
		scanf("%d", &post[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	root = create_tree(0, n - 1, 0, n - 1);
	traverse_tree(root);

	return 0;
}