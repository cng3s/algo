
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxn = 100010;
int pos[maxn];

int main() {

	int n , ans = 0;
	scanf("%d", &n);
	
	int left = n - 1, num; // left存放除0以外不在本位上的数的个数
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		pos[num] = i;
		
		if (num == i && i != 0) {
			--left;
		}
	}
	
	int k = 0; // k存放除0以外当前不在本位上最小的数
	while (left > 0) {
		if (pos[0] == 0) {
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);
					++ans;
					break;
				}
				++k;
			}
		}
		
		
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			++ans;
			--left;
		}
	}



	printf("%d\n", ans);
	return 0;

}
