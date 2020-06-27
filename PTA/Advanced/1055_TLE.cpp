#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <numeric>
#include <cstring>
using namespace std;

int N, K;
struct record {
  char name[9];
  int age, worth;
};

int main() {
  scanf("%d%d", &N, &K);
  vector<record> people(N);
  for (auto i = 0; i < N; ++i)
    scanf("%s%d%d", people[i].name, &people[i].age, &people[i].worth);
  sort(people.begin(), people.end(), 
    [](const record& lhs, const record& rhs) -> bool { return lhs.age < rhs.age; });

  int M, Amin, Amax;
  for (auto case_cnt = 1; case_cnt <= K; ++case_cnt) {
    scanf("%d%d%d", &M, &Amin, &Amax);
    auto lowIt = lower_bound(people.begin(), people.end(), Amin,
      [](const record& lhs, const int Amin) -> bool {
        return lhs.age < Amin;
      });

    printf("Case #%d:\n", case_cnt);

    if (lowIt == people.end()) {
      printf("None\n");
    } else {
      vector< vector<record>::iterator > res;
      for (; lowIt != people.end() && lowIt->age <= Amax; ++lowIt)
        res.emplace_back(lowIt);

      if (res.size() != 0) {
        sort(res.begin(), res.end(),
          [](const vector<record>::iterator& lhs, const vector<record>::iterator& rhs) -> bool {
            return lhs->worth > rhs->worth ||
              (lhs->worth == rhs->worth && lhs->age < rhs->age) ||
              (lhs->worth == rhs->worth && lhs->age == rhs->age && strcmp(lhs->name, rhs->name) < 0);
          });

        for (auto i = 0; i < M && i != res.size(); ++i)
          printf("%s %d %d\n", res[i]->name, res[i]->age, res[i]->worth);
      } else {
        printf("None\n");
      }
    }
  }

}