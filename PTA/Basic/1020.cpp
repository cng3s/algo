/* case 3 无法通过 */
#pragma warning(disable : 4996)
#include <cstdio>
#include <map>
using namespace std;

#define MAXN 1000
int N, M;
map<double, double, greater<double>> price_idx;

int main()
{
	double tmp, sum = 0;
	double left[MAXN];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &tmp);
		left[i] = tmp;
	}
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &tmp);
		price_idx.insert({ tmp / left[i], left[i] });
	}
	for (auto it : price_idx) {
		if (M < it.second) {
			sum += it.first * M;
			break;
		}
		sum += it.first * it.second;
		M -= int(it.second);
	}
	printf("%.2lf", sum);

	return 0;
}