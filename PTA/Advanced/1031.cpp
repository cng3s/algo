#pragma warning(disable : 4996)

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

string str;
int N;
int main() {
  cin >> str;
  int n13 = 1, n2 = N = str.size();
  while (n13 <= n2) {
    ++n13;
    n2 -= 2;
  }
  --n13;
  n2 += 2;

  for (int i = 0, j = N-1; i < n13-1; ++i, --j) {
    printf("%c", str[i]);
    for (int k = 0; k < n2-2; ++k) printf(" ");
    printf("%c\n", str[j]);
  }
  for (int i = n13-1; i < n13 + n2-1; ++i) {
    printf("%c", str[i]);
  }

  return 0;
}