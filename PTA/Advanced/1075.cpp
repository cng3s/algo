#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10010;
struct Student {
  int id;
  int score[6];
  bool print;
  int score_total;
  int solve;
} stu[maxn];
int n, k, m;
int full[6];

bool cmp(const Student& a, const Student& b)
{
  if (a.score_total != b.score_total) return a.score_total > b.score_total;
  else if (a.solve != b.solve) return a.solve > b.solve;
  else return a.id < b.id;
}

void init()
{
  for (int i = 1; i <= n; ++i) {
    stu[i].id = i;
    stu[i].score_total = 0;
    stu[i].solve = 0;
    stu[i].print = false;
    memset(stu[i].score, - 1, sizeof(stu[i].score));
  }
}

int main()
{
  scanf("%d%d%d", &n, &k, &m);
  init();
  for (int i = 1; i <= k; ++i)
    scanf("%d", &full[i]);
  int userid, problemid, score_obtained;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &userid, &problemid, &score_obtained);
    if (score_obtained != -1) // 如果考生有能通过编译的提交，即使分数为0也要打印
      stu[userid].print = true;
    if (score_obtained == -1 && stu[userid].score[problemid] == -1)
      stu[userid].score[problemid] = 0;
    if (score_obtained == full[problemid] && stu[userid].score[problemid] < full[problemid])
      ++stu[userid].solve;
    if (score_obtained > stu[userid].score[problemid])
      stu[userid].score[problemid] = score_obtained;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j)
      if (stu[i].score[j] != -1)
        stu[i].score_total += stu[i].score[j];
  }

  sort(stu + 1, stu + n + 1, cmp);

  int r = 1;
  for (int i = 1; i <= n && stu[i].print ; ++i) {
    // 如果当前考生分数低于前一位考生分数， 则排名为在该考生之前的总考生数
    if (i > 1 && stu[i].score_total != stu[i - 1].score_total)
      r = i;
    printf("%d %05d %d", r, stu[i].id, stu[i].score_total);
    for (int j = 1; j <= k; ++j) {
      if (stu[i].score[j] == -1)
        printf(" -");
      else
        printf(" %d", stu[i].score[j]);
    }
    printf("\n");
  }
}