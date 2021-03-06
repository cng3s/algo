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

  int *p = ipt[0], *a = ipt[1], paysucc = true;
  for (int i = 0; i < 2; ++i) {
    if (ipt[0][i] > ipt[1][i]) {
      swap(p, a);
      paysucc = false;
      break;
    } else if (ipt[0][i] < ipt[1][i])
      break;
  }
  for (int i = 2; i > -1; --i) {
    res[i] = a[i] - p[i];
    if (res[i] < 0 and i != 0) {
      res[i] += change[i];
      a[i-1] -= 1;
    }
  }
  
  if (!paysucc)
    printf("-");
  for (int i = 0; i < 3; ++i) {
    printf("%d", res[i]);
    if (i != 2)
      printf(".");
  }
  return 0;
}