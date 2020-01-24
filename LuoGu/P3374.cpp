#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> bit;
vector<long long> res;

int lowbit(int x)
{
	return x & (-x);
}

void add(int i, int x)
{
	while (i <= n) {
		bit[i] += x;
		i += lowbit(i);
	}
}

long long sum(int i)
{
	long long ret = 0;
	while (i) {
		ret += bit[i];
		i -= lowbit(i);
	}
	return ret;
}

int main()
{
	int i, x, y, z;
	long long s;

	cin >> n >> m;

	bit.resize(n + 1);
	for (i = 0; i < n; ++i) {
		cin >> x;
		add(i + 1, x);
	}
	for (i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		switch (x) {
		case 1:
			add(y, z);
			break;
		case 2:
			s = sum(z) - sum(y - 1);
			res.push_back(s);
			break;
		}
	}


	for (i = 0; i < res.size(); ++i) {
		cout << res[i];
		if (i + 1 != res.size())
			cout << endl;
	}

	return 0;
}