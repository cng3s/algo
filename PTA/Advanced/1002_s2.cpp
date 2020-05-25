#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

const int maxn = 10e3 + 10;
int K, expo;
double arr[maxn], coef;

int main() {
  int times = 2;
  while (times--) {
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
      scanf("%d%lf", &expo, &coef);
      arr[expo] += coef;
    }
  }
  
  int cnt = 0;
  for (int i = 0; i <= 1000; ++i) {
    if (arr[i] != 0)
      ++cnt;
  }
  
  printf("%d", cnt);
  for (int i = 1000; i >= 0; --i) {
    if (arr[i] != 0)
      printf(" %d %.1lf", i, arr[i]);
  }

  return 0;
}
