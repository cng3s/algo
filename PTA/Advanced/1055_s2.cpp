#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;

int Age[maxn] = { 0 };
struct Person {
  int age, worth;
  char name[10];
} people[maxn], valid[maxn];  // 所有人、在各自年龄中财富值在100名内

bool cmp(const Person& a, const Person& b) {
  if (a.worth != b.worth) return a.worth > b.worth;
  else if (a.age != b.age) return a.age < b.age;
  return strcmp(a.name, b.name) < 0;
}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%s%d%d", people[i].name, &people[i].age, &people[i].worth);
  sort(people, people + n, cmp);
  int validNum = 0;
  for (int i = 0; i < n; ++i) {
    if (Age[people[i].age] < 100) {
      ++Age[people[i].age];
      valid[validNum++] = people[i];
    }
  }

  int m, ageL, ageR;
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d%d", &m, &ageL, &ageR);
    printf("Case #%d:\n", i);
    int printNum = 0;
    for (int j = 0; j < validNum && printNum < m; ++j) {
      if (valid[j].age >= ageL && valid[j].age <= ageR) {
        printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
        printNum++;
      }
    }

    if (printNum == 0)
      printf("None\n");
  }
}