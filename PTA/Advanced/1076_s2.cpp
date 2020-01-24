// 优化：超出L提前返回，不过从OJ上看这个小优化仅减少内存空间，速度上反而有点减慢了。

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_USERS 1001

struct user {
	int index;
	vector<int> followers, followings;
} users[MAX_USERS];
bool visited[MAX_USERS] = { false };
int layers[MAX_USERS] = { 0 };
int N, L, res;

void BFS(int index)
{
	visited[index] = true;
	queue<int> q;
	q.push(index);

	while (!q.empty()) {
		index = q.front();
		q.pop();
		if (layers[index] + 1 > L)
			return;
		vector<int> *followers = &users[index].followers;
		for (size_t i = 0; i < followers->size(); ++i) {
			int followerindex = (*followers)[i];
			if (visited[followerindex] == false) {
				layers[followerindex] = layers[index] + 1;
				visited[followerindex] = true;
				q.push(followerindex);
			}
		}
	}
}

void clear()
{
	res = 0;
	for (int i = 1; i <= N; ++i) {
		visited[i] = false;
		layers[i] = 0;
	}
}

int main()
{
	int M, tmp;

	cin >> N >> L;
	for (int i = 1; i <= N; ++i) {
		cin >> M;
		users[i].followings.resize(M);
		for (int j = 0; j < M; ++j) {
			cin >> tmp;
			users[i].followings[j] = tmp;
			users[tmp].followers.push_back(i);
		}
	}

	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> tmp;
		BFS(tmp);
		for (int j = 1; j <= N; ++j) {
			if (layers[j] <= L && layers[j] > 0)
				res += 1;
		}
		cout << res << endl;
		clear();
	}

	return 0;
}