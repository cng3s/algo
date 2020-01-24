#include <iostream>

using namespace std;

int main()
{
	int totaltime = 0, N, i, floor = 0, n;

	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> n;
		if (floor < n) {
			totaltime += 6 * (n - floor);
		} else if (floor > n) {
			totaltime += 4 * (floor - n);
		}
		totaltime += 5;
		floor = n;
	}

	cout << totaltime;

	return 0;
}