/*
 * 树状数组以Push key的key作为索引，bitree[lowbit(key)]存储0 ... key的出现次数
 * 通过统计各个key的出现次数来确定Median key。
 * 这道题还是比较困难的。
 * */

#include <iostream>
#include <queue>

using namespace std;

#define CAPCITY 100001

typedef long long ll;

unsigned bitree[CAPCITY], mystack[CAPCITY]; // 树状数组 binary index tree
unsigned treesize = CAPCITY, stacksize = 0;
unsigned* top = mystack;
queue<int> res; // 存储最后要输出的结果

inline int lowbit(int index)
{
	return index & (-index);
}

void add(int index, int x)
{
	while (index <= treesize) {
		bitree[index] += x;
		index += lowbit(index);
	}
}

ll sum(int index)
{
	ll sum = 0;

	while (index) {
		sum += bitree[index];
		index -= lowbit(index);
	}
	return sum;
}

void Push(int index)
{
	(*top++) = index;
	add(index, 1);
	++stacksize;
}

void Pop()
{
	if (stacksize == 0) {
		res.push(-1);
		return;
	}

	unsigned n = *(--top);
	--stacksize;
	add(n, -1);
	res.push(n);
}

void PeekMedian()
{
	if (stacksize == 0) {
		res.push(-1);
		return;
	}

	int index, mid;
	ll mysum;

	if (stacksize % 2 == 0) {
		index = stacksize / 2;
	} else {
		index = (stacksize + 1) / 2;
	}

	// 二分法通过数字出现次数在树状数组中查找中位数
	int left = 0, right = CAPCITY;
	while (left < right - 1) {
		mid = (left + right) / 2;
		mysum = sum(mid);
		if (mysum < index) {
			left = mid;
		} else {
			right = mid;
		}
	}
	res.push(left + 1);
}

int main()
{
	string opstr;
	unsigned opnum;
	int N, i;

	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> opstr;
		switch (opstr[1]) {
		case 'u': // Push
			cin >> opnum;
			Push(opnum);
			break;
		case 'o': // Pop
			Pop();
			break;
		case 'e': // PeekMedian
			PeekMedian();
			break;
		}
	}

	while (!res.empty()) {
		opnum = res.front();
		res.pop();
		if (opnum == -1) {
			cout << "Invalid";
		} else {
			cout << opnum;
		}
		cout << endl;
	}

	return 0;
}
