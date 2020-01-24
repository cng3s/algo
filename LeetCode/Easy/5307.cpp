#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

bool check(int n)
{
	int bit;
	while (n != 0) {
		bit = n % 10;
		n = n / 10;
		if (bit == 0)
			return false;
	}
	return true;
}

int main()
{
	int N, a, b;
	scanf("%d", &N);
	a = 1;
	b = N - 1;

	for (; a <= N / 2 && b >= N / 2; ++a, --b) {
		if (check(a) && check(b))
			break;
	}
	printf("[%d,%d]", a, b);

	return 0;
}