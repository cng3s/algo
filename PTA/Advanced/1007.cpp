#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K;
	scanf("%d", &K);
	
	vector<int> vec(K);
	int leftidx = 0, rightidx = K-1, tmp_leftidx = 0;
	long tmp = 0, sum = -1;

	for (int i = 0; i < K; ++i) {
		scanf("%d", &vec[i]);
		tmp += vec[i];

		if (tmp > sum) {
			sum = tmp;
			rightidx = i;
			leftidx = tmp_leftidx;
		} else if (tmp < 0) {
			tmp_leftidx = i + 1;
			tmp = 0;
		}
	}

	if (sum < 0) {
		sum = 0;
	}
	printf("%ld %d %d", sum, vec[leftidx], vec[rightidx]);

    return 0;
}