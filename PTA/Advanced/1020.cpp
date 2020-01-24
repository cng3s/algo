#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

vector<unsigned> inorder;
vector<unsigned> postorder;
unsigned N = 0; // 存储vector元素个数

struct BST_Node {
	unsigned data;
	struct BST_Node* left, * right;

	BST_Node() : left(nullptr), right(nullptr), data(0) {}
	BST_Node(struct BST_Node* l, struct BST_Node* r, unsigned d)
		: left(l), right(r), data(d) {}
};

void LevelOrderTraverse(struct BST_Node* bst)
{
	queue<BST_Node*> q;
	BST_Node* cur = bst;

	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		cout << cur->data;
		q.pop();
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
		if (!q.empty())
			cout << " ";
	}
	
}

BST_Node* CreateBST(int post_root, int in_left, int in_right)
{
	if (in_left > in_right)
		return nullptr;
	if (in_left == in_right)
		return new BST_Node(nullptr, nullptr, postorder[post_root]);

	unsigned rootval = postorder[post_root];
	int idx = in_left;

	while (inorder[idx] != rootval)
		++idx;
	
	BST_Node* node = new BST_Node();
	node->data = rootval;
	node->left = CreateBST(post_root - in_right + idx - 1, in_left, idx - 1);
	node->right = CreateBST(post_root - 1, idx + 1, in_right);
	return node;
}

int main()
{
	unsigned n, i;

	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> n;
		postorder.push_back(n);
	}
	for (i = 0; i < N; ++i) {
		cin >> n;
		inorder.push_back(n);
	}

	BST_Node* bst = CreateBST(N-1, 0, N - 1);
	LevelOrderTraverse(bst);

	return 0;
}