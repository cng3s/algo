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

int change[3] = {0, 17, 29}, ipt[2][3], res[3] = {0};

int main()
{
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &ipt[i][j]);
      getchar();
    }
  }

  int cf = 0;
  for (int i = 2; i >= 0; --i) {
    res[i] = ipt[0][i] + ipt[1][i] + cf;
    cf = 0;
    if (i != 0 and res[i] >= change[i]) {
      res[i] %= change[i];
      cf = 1;
    }
  }

  for (int i = 0; i < 3; ++i) {
    printf("%d", res[i]);
    if (i != 2)
      printf(".");
  }
  return 0;
}