/* 20:00 感觉和A1057 Stack类似，树状数组搞起来
 * 20:56 居然有三个例子运行超时，那估计不是用树状数组了
 * 树状数组主要的时间复杂度应该是在add(index, x)过程中维护树状数组
 * 另外，cin换成scanf时间居然可以缩短一倍。
 * P.S. 这题也可以用最大堆来做（priority_queue），但是一样会超时，就不写了
 * 还是在线更新的方法最好，时间复杂度最低
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define CAPCITY 200000
typedef long long ll;
typedef long int li;

li bitree[CAPCITY];
int bitreesize = 0;

inline int lowbit(int index)
{
	return index & (-index);
}

ll sum(int index)
{
	ll ret = 0;
	while (index) {
		ret += bitree[index];
		index -= lowbit(index);
	}
	return ret;
}

void add(int index, int x)
{
	while (index < CAPCITY) {
		bitree[index] += x;
		index += lowbit(index);
	}
}

int main()
{
	int N, i, n;
	
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &n);
		add(n, 1);
	}
	bitreesize += N;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &n);
		add(n, 1);
	}
	bitreesize += N;

	// 使用二分法查找出现次数是中位数的index
	int left = 0, right = CAPCITY, mid, index;
	ll mysum;
	if (bitreesize % 2 == 0) {
		index = bitreesize / 2;
	} else {
		index = (bitreesize + 1) / 2;
	}
	while (left < right - 1) {
		mid = (left + right) / 2;
		mysum = sum(mid);
		if (mysum < index) {
			left = mid;
		} else {
			right = mid;
		}
	}
	printf("%d", left + 1);

	return 0;
}