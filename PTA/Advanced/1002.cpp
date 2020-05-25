
// 这道题一定要注意判0，如果是coef == 0，则不用计算cnt和输出
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int K, expo;
double coef;
map<int, double, greater<int>> exp_coef;
int main() {
  int times = 2, cnt = 0;
  while (times--) {
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
      scanf("%d%lf", &expo, &coef);
      exp_coef[expo] += coef;
    }
  }

  for (const auto &it : exp_coef) {
    if (it.second != 0)
      ++cnt;
  }

  printf("%d", cnt);
  for (const auto &it : exp_coef) {
    if (it.second != 0)
      printf(" %d %.1lf", it.first, it.second);
  }

  return 0;
}
