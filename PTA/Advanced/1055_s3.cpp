#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

struct record {
  char name[9];
  int age, worth;
};

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  vector<record> people(N);
  vector<record*> valid_people;
  array<int, 201> age = { 0 };
  for (auto i = 0; i < N; ++i)
    scanf("%s%d%d", people[i].name, &people[i].age, &people[i].worth);

  sort(people.begin(), people.end(),
    [](const record& lhs, const record& rhs) -> bool {
      if (lhs.worth != rhs.worth) return lhs.worth > rhs.worth;
      else if (lhs.age != rhs.age) return lhs.age < rhs.age;
      return strcmp(lhs.name, rhs.name) < 0;
    });
  for (auto& e : people) {
    if (age[e.age] < 100) {
      ++age[e.age];
      valid_people.push_back(&e);
    }
  }

  int M, Amin, Amax;
  for (auto case_cnt = 1; case_cnt <= K; ++case_cnt) {
    auto print_cnt = 0;
    scanf("%d%d%d", &M, &Amin, &Amax);
    printf("Case #%d:\n", case_cnt);
    for (auto &e : valid_people) {
      if (print_cnt == M) break;
      if (e->age <= Amax && e->age >= Amin) {
        printf("%s %d %d\n", e->name, e->age, e->worth);
        ++print_cnt;
      }
    }
    if (print_cnt == 0)
      printf("None\n");
  }
}