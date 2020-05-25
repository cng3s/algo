
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <list>
#include <map>
#include <functional>
using namespace std;

typedef struct entry {
  double coef;
  int expo;
} entry;
int K, expo;
double coef;
list<entry> p[2];
map<int, double, greater<int>> res;

int main() {
  int times = 2;
  while (times--) {
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
      entry e;
      scanf("%d%lf", &e.expo, &e.coef);
      p[times].push_back(e);
    }
  }

  for (const auto &it0 : p[0]) {
    for (const auto &it1 : p[1]) {
      int expo = it0.expo + it1.expo;
      double coef = it0.coef * it1.coef;
      res[expo] += coef;
    }
  }

  int cnt = 0;
  for (const auto &it : res) {
    if (it.second != 0)
      ++cnt;
  }

  printf("%d", cnt);
  for (const auto &it : res) {
    if (it.second != 0)
      printf(" %d %.1lf", it.first, it.second);
  }
  
  return 0;
}
