// 《算法笔记》P427
#include <iostream>
#include <algorithm>
using namespace std;

int f[50][50], dp[50][50];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> f[i][j];
		}
	}

	for (int j = 0; j < n; ++j) {
		dp[n-1][j] = f[n-1][j];
	}

	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
		}
	}

	cout << dp[0][0] << endl;

	return 0;
}