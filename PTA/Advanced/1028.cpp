
// 这道题第一次提交错误是因为name[8]，而字符串应该有'/0'，所以至少是9位长度
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int N, C;
struct record {
  int id, grade;
  char name[10];
};

int main() {
  scanf("%d%d", &N, &C);
  vector<record> records(N);

  for (int i = 0; i < N; ++i)
    scanf("%d%s%d", &records[i].id, records[i].name, &records[i].grade);

  if (C == 1) {
    sort(records.begin(), records.end(),
      [](const record& lhs, const record& rhs) -> bool {
        return lhs.id < rhs.id;
      });
  } else if (C == 2) {
    sort(records.begin(), records.end(),
      [](const record& lhs, const record& rhs) -> bool {
        auto res = strcmp(lhs.name, rhs.name);
        return res < 0 or (res == 0 and lhs.id < rhs.id);
      });
  } else if (C == 3) {
    sort(records.begin(), records.end(),
      [](const record& lhs, const record& rhs) -> bool {
        return lhs.grade < rhs.grade or (lhs.grade == rhs.grade and lhs.id < rhs.id);
      });
  }

  for (int i = 0; i != records.size(); ++i)
    printf("%06d %s %d\n", records[i].id, records[i].name, records[i].grade);
}