#pragma once

#include <iostream>
#include <set>

using namespace std;

#define BITMAP_CAPCITY 3500
bool bitmap[BITMAP_CAPCITY];
set<unsigned> res;

void get_Callatz_nums(unsigned n) {
	if (bitmap[n])
		return;
	
	unsigned cur = n;

	while (cur != 1) {
		if (cur % 2 == 0)
			cur /= 2;
		else
			cur = (3 * cur + 1) / 2;

		if (bitmap[cur] == 0) {
			bitmap[cur] = 1;
			continue;
		}
		break;
	}
	res.erase(cur);
	res.insert(n);
	bitmap[n] = 1;

}

void main_p1005_s1() {
	unsigned K, n, i;

	for (i = 0; i < BITMAP_CAPCITY; i++)
		bitmap[i] = 0;

	cin >> K;
	for (i = 0; i < K; ++i) {
		cin >> n;
		get_Callatz_nums(n);
	}

	set<unsigned>::iterator iter;
	for (iter = --res.end(); iter != res.begin(); --iter) {
		cout << *iter << " ";
	}
	cout << *iter;
}