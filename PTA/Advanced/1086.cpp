#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define MAXN 31
struct node {
	int e;
	struct node* l, * r;
	node(int e_) : e(e_), l(nullptr), r(nullptr) {}
};
int n;
vector<int> pre, in, post;

struct node* create(int prel, int prer, int inl, int inr)
{
	if (prel > prer)
		return nullptr;
	if (prel == prer)
		return new node(pre[prel]);
	int inidx, leftnum;
	struct node * cur = new node(pre[prel]);
	for (inidx = inl; inidx <= inr; ++inidx) {
		if (in[inidx] == pre[prel])
			break;
	}
	leftnum = inidx - inl;
	cur->l = create(prel + 1, prel + leftnum, inl, inidx - 1);
	cur->r = create(prel + leftnum + 1, prer, inidx + 1, inr);
	return cur;
}

void post_traverse(struct node* cur)
{
	if (cur->l) post_traverse(cur->l);
	if (cur->r) post_traverse(cur->r);
	post.push_back(cur->e);
}

int main()
{
	int i, tmp;
	string op;
	stack<int> nums;
	scanf("%d", &n);

	for (i = 0; i < 2*n; ++i) {
		cin >> op;
		switch (op[1]) {
		case 'u':
			scanf("%d", &tmp);
			pre.push_back(tmp);
			nums.push(tmp);
			break;
		case 'o':
			in.push_back(nums.top());
			nums.pop();
			break;
		}
	}
	struct node * root = create(0, pre.size() - 1, 0, in.size() - 1);
	post_traverse(root);
	printf("%d", post[0]);
	for (i = 1; i < post.size(); ++i)
		printf(" %d", post[i]);

	return 0;
}