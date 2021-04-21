
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  
  int Nc, Np;
  long ans = 0;

  scanf("%d", &Nc);
  vector<int> coupons(Nc);
  for (int i = 0; i < Nc; ++i) {
    scanf("%d", &coupons[i]);
  }

  scanf("%d", &Np);
  vector<int> products(Np);
  for (int i = 0; i < Np; ++i) {
    scanf("%d", &products[i]);
  }

  sort(coupons.begin(), coupons.end(),
      [](int lhs, int rhs) { return lhs > rhs; });
  sort(products.begin(), products.end(),
      [](int lhs, int rhs) { return lhs > rhs; });


  int i = 0, j = 0;
  for (; i < Nc && j < Np && coupons[i] > 0 && products[j] > 0; ++i, ++j)  {
    ans += coupons[i] * products[j];
  }

  for (i = Nc-1, j = Np-1; i >= 0 && j >= 0 && coupons[i] < 0 && products[j] < 0; --i, --j) {
    ans += coupons[i] * products[j];
  }

  printf("%ld\n", ans);

  return 0;
}

