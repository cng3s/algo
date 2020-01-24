/* 使用并查集 */
#pragma warning(disable : 4996)
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

#define MAX_PERSONS 2000
map<string, string> father;
map<string, int> weight, gang_time, member_num, head_idx;
int N, K;

string ufset_find_father(string p)
{
	string pfather = p;
	while (father[pfather] != pfather)
		pfather = father[pfather];

	if (weight[pfather] < weight[p]) {
		father[pfather] = p;
		father[p] = p;
		return p;
	}
	return pfather;
}

void ufset_union(string person1, string person2)
{
	string father1 = ufset_find_father(person1)
		, father2 = ufset_find_father(person2);
	if (weight[father1] > weight[father2])
		father[father2] = father1;
	else
		father[father1] = father2;
}

int main()
{
	string name1, name2;
	int time;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		cin >> name1 >> name2 >> time;
		weight[name1] += time;
		weight[name2] += time;
		if (father.find(name1) == father.end())
			father[name1] = name1;
		if (father.find(name2) == father.end())
			father[name2] = name2;
		ufset_union(name1, name2);
	}

	for (auto iter : father) {
		string iterfather = ufset_find_father(iter.first);
		gang_time[iterfather] += weight[iter.first];
		member_num[iterfather] += 1;
	}
	for (auto iter : member_num) {
		if (iter.second > 2 && gang_time[iter.first] / 2 > K)
			head_idx[iter.first] = iter.second;
	}
	cout << head_idx.size();
	for (auto iter : head_idx)
		cout << endl << iter.first << " " << iter.second;

	return 0;
}