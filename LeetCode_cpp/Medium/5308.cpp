#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c, mask = 1, cnt = 0;

	scanf("%d%d%d", &a, &b, &c);
	if (b > a)
		swap(a, b);
	while (mask <= c || mask <= a || mask <= b) {
		int abit = a & mask, bbit = b & mask
			, cbit = c & mask;
		abit = abit / mask;
		bbit = bbit / mask;
		cbit = cbit / mask;
		if (cbit == 1 && abit == 0 && bbit == 0)
			cnt += 1;
		else if (cbit == 0 && abit == 1 && bbit == 1)
			cnt += 2;
		else if (cbit == 0 && (abit == 1 || bbit == 1))
			cnt += 1;
		mask <<= 1;
	}
	printf("%d", cnt);
	
}