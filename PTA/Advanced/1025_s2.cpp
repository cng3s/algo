/* 方法2，但比第一种慢，应该是sort需要比较久。 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<unsigned> inorder;
vector<unsigned> postorder;
vector<pair<unsigned, unsigned>> levelorder;
unsigned N = 0; // 存储vector元素个数

bool mycmp(pair<unsigned, unsigned> p1, pair<unsigned, unsigned> p2)
{
	return p1.first < p2.first;
}

void pre_order_seq(int postroot, int inleft, int inright, int treeindex)
{
	if (inleft > inright)
		return;

	unsigned rootval = postorder[postroot], idx = 0;

	while (idx <= inright && inorder[idx] != rootval)
		++idx;

	levelorder.push_back(make_pair(treeindex, rootval));

	pre_order_seq(postroot - inright + idx - 1, inleft, idx - 1, 2 * treeindex + 1);
	pre_order_seq(postroot - 1, idx + 1, inright, 2 * treeindex + 2);
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

	pre_order_seq(N - 1, 0, N - 1, 0);
	sort(levelorder.begin(), levelorder.end(), mycmp);

	for (i = 0; i < N; ++i) {
		cout << levelorder[i].second;
		if (i != (N - 1))
			cout << " ";
	}

	return 0;
}