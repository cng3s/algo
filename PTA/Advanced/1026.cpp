#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <cmath>
#include <functional>
using namespace std;

double C1, C2;

int main() {
  scanf("%lf%lf", &C1, &C2);
  double sum = (C2 - C1) / 100, mymod = fmod(sum, 3600);
  int hh = sum / 3600, mm = mymod / 60;
  double ss = fmod(mymod, 60);

  printf("%02d:%02d:%02d", hh, mm, int(round(ss)));

  return 0;
}
