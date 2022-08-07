#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int v, h;
	struct node *l, *r;
	node(int v_) : v(v_), h(1), l(nullptr), r(nullptr) {}
};

// 获取以root为根子树高度
int get_height(const struct node* root)
{ return root == nullptr ? 0 : root->h; }

// 计算root的平衡因子
int get_balance_factor(const struct node* root)
{ return get_height(root->l) - get_height(root->r); }

// 更新root的高度
void update_height(struct node* root)
{ root->h = max(get_height(root->l), get_height(root->r)) + 1; }

// 在root中寻找数据域为x的节点
void search(struct node* root, int x)
{
	if (root == nullptr)
		return;
	if (root->v == x)
		printf("%d ", root->v);
	else if (root->v > x)
		search(root->l, x);
	else
		search(root->r, x);
}

// 左旋 Left Rotation
// 指针引用（*&）是当想要彻底地改变传进来的root指针指向的对象时使用
// 就是引用一个指针类型而已，很简单不要想复杂。
void L(struct node* &root)
{
	struct node *tmp = root->r;
	root->r = tmp->l;
	tmp->l = root;
	update_height(root);
	update_height(tmp);
	root = tmp;
}

// 右旋 Right Rotation
void R(struct node* &root)
{
	struct node *tmp = root->l;
	root->l = tmp->r;
	tmp->r = root;
	// 一定是先更新root再更新tmp
	update_height(root);
	update_height(tmp);
	root = tmp;
}

// 插入权值为v的节点
void insert(struct node*& root, int v)
{
	if (root == nullptr) {
		root = new node(v);
		return;
	}
	if (root->v < v) { // R*
		insert(root->r, v);
		update_height(root);
		if (get_balance_factor(root) == -2) { // 右子树失衡，avl需要平衡
			if (get_balance_factor(root->r) == 1)// RL型
				R(root->r);
			L(root);
		}
	} else { // L*
		insert(root->l, v);
		update_height(root);
		if (get_balance_factor(root) == 2) {
			if (get_balance_factor(root->l) == -1)// LR
				L(root->l);
			R(root);
		}
	}
}

// 创建avl tree
struct node* create_avl(int data[], int n)
{
	struct node* root = nullptr;
	for (int i = 0; i < n; ++i) {
		insert(root, data[i]);
	}
	return root;
}

void level_traverse(struct node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		struct node *cur = q.front();
		q.pop();
		printf("%d ", cur->v);
		if (cur->l)
			q.push(cur->l);
		if (cur->r)
			q.push(cur->r);
	}
}

int main()
{
	int i, n;
	int data[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &data[i]);
	struct node *root = create_avl(data, n);
	level_traverse(root);

	return 0;
}
