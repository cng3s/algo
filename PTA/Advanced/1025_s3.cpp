
/* 方法3，结合方法1与方法2的优点。 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int postroot, inleft, inright;

	node(int pos, int lef, int rig)
		: postroot(pos), inleft(lef), inright(rig) {}
};

vector<unsigned> inorder;
vector<unsigned> postorder;
queue<node*> call_seq;
unsigned N = 0; // 存储vector元素个数

void level_order_seq()
{
	struct node* cur = call_seq.front();
	call_seq.pop();

	int root = cur->postroot, left = cur->inleft, right = cur->inright;
	int rootval = postorder[root], index = 0;

	while (inorder[index] != rootval)
		++index;

	if (left <= index - 1)
		call_seq.push(new node(root - right + index - 1, left, index - 1));
	if (index + 1 <= right)
		call_seq.push(new node(root - 1, index + 1, right));

	cout << rootval;
	if (call_seq.empty()) {
		return;
	}
	cout << " ";
	level_order_seq();
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
	
	call_seq.push(new node(N - 1, 0, N - 1));
	level_order_seq();

	return 0;
}