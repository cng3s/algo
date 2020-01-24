#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define CAPCITY 100

struct BST_Node {
	int left, right;
	int data;
} bst[CAPCITY];

vector<int> datas;
queue<int> res;
int cur = 0;

void create_BST(int index)
{
	if (index == -1)
		return;
	
	create_BST(bst[index].left);
	bst[index].data = datas[cur++];
	create_BST(bst[index].right);
}

void level_order_traverse()
{
	queue<int> indexs;
	int cur;

	indexs.push(0);
	while (!indexs.empty()) {
		cur = indexs.front();
		indexs.pop();
		if (cur == -1)
			continue;
		res.push(bst[cur].data);
		indexs.push(bst[cur].left);
		indexs.push(bst[cur].right);
	}
}

int main()
{
	int N, i;
	int tmp1, tmp2;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> tmp1 >> tmp2;
		bst[i].left = tmp1;
		bst[i].right = tmp2;
	}
	for (i = 0; i < N; ++i) {
		cin >> tmp1;
		datas.push_back(tmp1);
	}
	
	sort(datas.begin(), datas.end());
	create_BST(0);
	level_order_traverse();

	while (!res.empty()) {
		tmp1 = res.front();
		res.pop();
		cout << tmp1;
		if (!res.empty())
			cout << " ";
	}

	return 0;
}