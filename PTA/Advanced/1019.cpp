#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <string>
#include <functional>
using namespace std;

int N, b;
vector<int> res;

int main() {
  scanf("%d%d", &N, &b);
  int curN = N;
  while (curN) {
    res.push_back(curN % b); // 高位在后，低位在前
    curN /= b;
  }
  bool succ = true;
  for (int i = 0, j = res.size()-1;
        i < j; ++i, --j) {
    if (res[i] != res[j]) {
      succ = false;
      break;
    }
  }

  if (succ)
    printf("Yes\n");
  else
    printf("No\n");
  printf("%d", res[res.size()-1]);
  for (int i = res.size()-2; i > -1; --i)
    printf(" %d", res[i]);

}