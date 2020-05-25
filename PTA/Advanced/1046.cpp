#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int N, dis[maxn], M;
vector<int> res;
int dist(int src, int dst, int limit) {
  int sum1 = 0;
  for (int i = src; ; ++i) {
      if (i > N)
        i = 1;
      if (i == dst or sum1 >= limit)
        break;
      sum1 += dis[i];
  }
  return sum1;
}

int main() { 
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d", &dis[i]);
 
  scanf("%d", &M);
  int src, dst;
  while (M--) {
    scanf("%d%d", &src, &dst);
    int sum1 = dist(src, dst, INT_MAX), sum2 = dist(dst, src, sum1);
    
    res.push_back(min(sum1, sum2));
  }

  for (int i = 0; i < res.size(); ++i)
    printf("%d\n", res[i]);

  return 0;
}
