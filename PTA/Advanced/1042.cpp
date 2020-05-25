#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 60;
int K, A[maxn], B[maxn], order[maxn];
int main() {
  scanf("%d", &K);
  for (int i = 1; i <= 54; ++i) {
    scanf("%d", &order[i]);
    A[i] = i;
  }

  int *src = A, *dst = B;
  while (K--) {
    for (int i = 1; i <= 54; ++i)
      dst[order[i]] = src[i];
    swap(dst, src);
  }

  for (int i = 1; i <= 54; ++i) {
    int m = (src[i]-1) / 13; // 判断花色
    if (m == 0)
      printf("S");
    else if (m == 1)
      printf("H");
    else if (m == 2)
      printf("C");
    else if (m == 3)
      printf("D");
    else if (m == 4)
      printf("J");

    int n = src[i] % 13;
    if (n == 0)
      printf("13");
    else
      printf("%d", n);
    if (i != 54)
      printf(" ");
  }

  return 0;
}