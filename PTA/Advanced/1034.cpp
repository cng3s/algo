#include <iostream>
#include <map>
#include <climits>
#include <string>
using namespace std;

#define MAXN 2000
#define INF INT_MAX

int graph[MAXN][MAXN] = { 0 };
int weight[MAXN] = { 0 };
bool visited[MAXN] = { false };
map<string, int> name_index;
map<int, string> index_name;
map<string, int> gangs;
int N, K, persons_cnt = 0;

int covert_name_to_index(string name)
{
	if (name_index.find(name) != name_index.end())
		return name_index[name];

	name_index[name] = persons_cnt;
	index_name[persons_cnt] = name;
	return persons_cnt++;
}

void DFS(int index, int &membercnt, int &head, int &weightsum)
{
	++membercnt;
	visited[index] = true;
	if (weight[index] > weight[head])
		head = index;

	for (int i = 0; i < persons_cnt; ++i) {
		if (graph[index][i] > 0) {
			weightsum += graph[index][i];
			graph[index][i] = 0;
			graph[i][index] = 0;
			if (!visited[i])
				DFS(i, membercnt, head, weightsum);
		}
	}
}

void DFS_traverse()
{
	for (int i = 0; i < persons_cnt; ++i) {
		if (visited[i] == false) {
			int membercnt = 0, head = i, weightsum = 0;
			DFS(i, membercnt, head, weightsum);
			if (weightsum > K&& membercnt > 2)
				gangs[index_name[head]] = membercnt;
		}
	}
}

int main()
{
	string name1, name2;
	int i, time, tmp1, tmp2;

	cin >> N >> K;
	for (i = 0; i < N; ++i) {
		cin >> name1 >> name2 >> time;
		tmp1 = covert_name_to_index(name1);
		tmp2 = covert_name_to_index(name2);
		weight[tmp1] += time;
		weight[tmp2] += time;
		// 这里写成graph[tmp1][tmp2] = time 导致有一个case死活过不去
		// 应该是tmp1 == tmp2时重置导致的case过不去
		graph[tmp1][tmp2] += time;
		graph[tmp2][tmp1] += time;
	}
	DFS_traverse();

	cout << gangs.size();
	for (auto iter = gangs.begin(); iter != gangs.end(); ++iter)
		cout << endl << iter->first << " " << iter->second;

	return 0;
}