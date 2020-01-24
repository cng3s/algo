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
		vector<int> *followers = &users[index].followers;
		for (int i = 0; i < followers->size(); ++i) {
			if (visited[(*followers)[i]] == false) {
				layers[(*followers)[i]] = layers[index] + 1;
				visited[(*followers)[i]] = true;
				q.push((*followers)[i]);
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