/* 个人感觉这种方法比树状数组实现更简单明了 */

#include <iostream>
#include <set>
#include <queue>
#include <climits>

using namespace std;

#define CAPCITY 100005

/*
 * minkeys, maxkeys维护mystack元素小的一半和大的一半
 * minkeys长度和maxkeys相同或比maxkeys多1
 * 使得中位数是minkeys的最后一个元素
 * */
multiset<unsigned> minkeys, maxkeys;
unsigned mystack[CAPCITY];
unsigned stacksize = 0, * top = mystack;
queue<int> res;
unsigned mid = UINT_MAX;

/*
 * adjust - 调整minkeys和maxkeys中元素使得符合定义要求
 * */
void adjust()
{
	multiset<unsigned>::iterator it;
	if (maxkeys.size() + 1 < minkeys.size()) {
		it = minkeys.end();
		--it;
		maxkeys.insert(*it);
		minkeys.erase(it);
	} else if (maxkeys.size() > minkeys.size()) {
		it = maxkeys.begin();
		minkeys.insert(*it);
		maxkeys.erase(it);
	}
	if (stacksize > 0) {
		it = minkeys.end();
		--it;
		mid = *it;
	}
}

void Push(unsigned n)
{
	*(top++) = n;
	if (n > mid) {
		maxkeys.insert(n);
	} else {
		minkeys.insert(n);
	}
	++stacksize;
	adjust();
}

void Pop()
{
	if (stacksize == 0) {
		res.push(-1);
		return;
	}

	unsigned num = *(--top);
	multiset<unsigned>::iterator it;
	--stacksize;
	res.push(num);
	if (num > mid) {
		// 这里直接maxkeys.erase(num)会删除所有的num而不是一个
		it = maxkeys.find(num);
		maxkeys.erase(it);
	} else {
		it = minkeys.find(num);
		minkeys.erase(it);
	}
	adjust();
}

void PeekMedian()
{
	if (stacksize == 0) {
		res.push(-1);
		return;
	}
	res.push(mid);
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