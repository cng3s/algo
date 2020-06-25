#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  using user_passwd = pair<string, string>;
  vector<user_passwd> userinfo(n);
  vector<int> modified_list;

  for (auto i = 0; i < n; ++i) {
    cin >> userinfo[i].first >> userinfo[i].second;
    auto modified = false;
    for (auto &ch : userinfo[i].second) {
      switch (ch) { 
      case '1': ch = '@'; modified = true; break;
      case '0': ch = '%'; modified = true; break;
      case 'O': ch = 'o'; modified = true; break;
      case 'l': ch = 'L'; modified = true; break;
      }
    }
    if (modified)
      modified_list.emplace_back(i);
  }

  if (modified_list.empty()) {
    if (n == 1)
      printf("There is %d account and no account is modified", n);
    else 
      printf("There are %d accounts and no account is modified", n);
  } else {
    printf("%lu\n", modified_list.size());
    for (auto ix : modified_list)
      cout << userinfo[ix].first << " " << userinfo[ix].second << "\n";
  }

}