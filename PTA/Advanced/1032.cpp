#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	char data;
	int next;
} list[100000];

int word1, word2;


int main()
{
	int idx1, idx2, n;
	char tmp;
	bool vis[100000];
	fill(vis, vis + 100000, false);
	scanf("%d%d%d", &word1, &word2, &n);
	for (int i = 0; i < n; ++i) {
		cin >> idx1 >> tmp >> idx2;
		list[idx1].data = tmp;
		list[idx1].next = idx2;
	}
	
	vector<int> visls1, visls2;
	for (int i = word1; i != -1; i = list[i].next) {
		visls1.push_back(i);
		vis[i] = true;
	}
	idx1 = -1;
	for (int i = word2; i != -1; i = list[i].next) {
		if (vis[i]) {
			idx1 = i;
			break;
		}
	}
	if (idx1 != -1)
		printf("%05d", idx1);
	else
		printf("-1");


	return 0;
}