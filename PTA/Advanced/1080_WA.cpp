#include <vector>
#include <array>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M, K;
struct record {
  int id, scores[2], schools[5], rank, avg;
};

int main()
{
  using quota_applicants = pair<int, vector<int>>;
  scanf("%d%d%d", &N, &M, &K);
  vector<quota_applicants> school(M);
  vector<record> applicants(N);

  for (auto i = 0; i < M; ++i)
    scanf("%d", &school[i].first);

  for (auto i = 0; i < N; ++i) {
    scanf("%d%d", &applicants[i].scores[0], &applicants[i].scores[1]);
    applicants[i].avg = (applicants[i].scores[0] + applicants[i].scores[1]) / 2;
    applicants[i].id = i;
    for (int h = 0; h < K; ++h)
      scanf("%d", &applicants[i].schools[h]);
  }

  sort(applicants.begin(), applicants.end(),
    [](const record& lhs, const record& rhs) -> bool {
      if (lhs.avg != rhs.avg) return lhs.avg > rhs.avg;
      return lhs.scores[0] > rhs.scores[0];
    });


  for (vector<record>::size_type i = 0; i < applicants.size(); ++i) {
    if (i > 0 && applicants[i - 1].avg == applicants[i].avg &&
      applicants[i].scores[0] == applicants[i - 1].scores[0]) {
      applicants[i].rank = applicants[i - 1].rank;
    }
    else {
      applicants[i].rank = i;
    }

    bool admit = false;
    for (int j = 0; j < K && !admit; ++j) {
      auto schoolix = applicants[i].schools[j];
      if (school[schoolix].first > 0) {
        --school[schoolix].first;
        school[schoolix].second.emplace_back(applicants[i].id);
        admit = true;
      }
      else {
        auto it = school[schoolix].second.rbegin();
        if (applicants[*it].rank == applicants[i].rank) {
          school[schoolix].second.emplace_back(applicants[i].id);
          admit = true;
        }
      }
    }
  }

  for (auto e : school) {
    if (e.second.size() > 0) {
      sort(e.second.begin(), e.second.end());
      printf("%d", e.second[0]);
      for (auto i = 1; i < e.second.size(); ++i)
        printf(" %d", e.second[i]);
    }
    printf("\n");
  }

}