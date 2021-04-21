#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX 100005
int N, maxval;

int main()
{
  vector<int> res;
  maxval = -1;

  scanf("%d", &N);
  vector<int> arr(N), arr2(N);

  for (int i = 0; i < N; ++i) {
    scanf("%d", &arr[i]);
    arr2[i] = arr[i];
  }


  sort(arr.begin(), arr.end());

  for (int i = 0; i < N; ++i) {
    if (arr[i] == arr2[i] && arr[i] > maxval) {
      //printf("%d  " , arr[i]);
      res.push_back(arr[i]);
    }
    if (arr2[i] > maxval)
      maxval = arr2[i];
  }

  int narr = int(res.size());
  printf("%d\n", narr);
  for (int i = 0; i < narr; ++i) {
    printf("%d", res[i]);
    if (i + 1 != narr)
      printf(" ");
  }
  printf("\n");

  return 0;
}
