#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
using namespace std;

// L: 德分和才分不能低于L才能被排名
// H：德分和才分不低于H的被认为是圣人，并按递减顺序排名他们的总分
// 才分低于H但德分不低于H的被认为是君子，并且按照递减排名，但他们列在圣人后
// 两者都低于H但德分不低于才分的被认为是愚人，在君子后排名（总分递减）
// 其余的并且两者分数都高于L的排名在愚人之后
// 如果总分相同（且是同一等级的），按德分降序排名，如果德分依然相同，按ID升序排名

struct man {
  int id;
  int virtue, talent;
};

int L, H, N;

enum { // 普通人，愚人，君子，圣人
  NOONE = 0, FOOL, NOBLEMAN, SAGE
};

inline int judge_level(const man& m)
{
  if (m.virtue >= H and m.talent >= H)
    return SAGE;
  else if (m.virtue >= H and m.talent < H)
    return NOBLEMAN;
  else if (m.virtue < H and m.talent < H and m.talent <= m.virtue)
    return FOOL;
  return NOONE;
}

int main() {
  scanf("%d%d%d", &N, &L, &H);
  vector<man> res;
  man ipt;
  for (auto i = 0; i < N; ++i) {
    scanf("%d%d%d", &ipt.id, &ipt.virtue, &ipt.talent);
    if (ipt.virtue >= L and ipt.talent >= L)
      res.emplace_back(ipt);
  } 

  sort(res.begin(), res.end(), [](const man& lhs, const man& rhs) {
    int lhslev = judge_level(lhs), rhslev = judge_level(rhs);
    if (lhslev == rhslev) {
        int lhssum = lhs.virtue + lhs.talent, rhssum = rhs.virtue + rhs.talent;
        if (lhssum == rhssum)
          return lhs.virtue == rhs.virtue ? lhs.id < rhs.id : lhs.virtue > rhs.virtue;
        return lhssum > rhssum;
    }
    return lhslev > rhslev;
  });

  printf("%lu\n", res.size());
  for(auto &it : res)
    printf("%d %d %d\n", it.id, it.virtue, it.talent);
}