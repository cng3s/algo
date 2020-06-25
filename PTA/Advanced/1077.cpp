#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    vector<string> ipt(n);
    vector<string::reverse_iterator> ipt_iters(n);
    string res;

    getchar();
    for (int i = 0; i < n; ++i) {
      getline(cin, ipt[i]);
      ipt_iters[i] = ipt[i].rbegin();
    }

    bool failed = false;
    while (1) {
      char cur = *ipt_iters[0];
      for (int i = 0; i < n; ++i) {
        if (ipt_iters[i] == ipt[i].rend() ||
            *(ipt_iters[i]) != cur) {
          failed = true;
          break;
        }
        ++(ipt_iters[i]);
      }
      if (failed)
        break;
      res.push_back(cur);
    }
    if (res.size()) {
      for (auto it = res.rbegin(); it != res.rend(); ++it)
        printf("%c", *it);
    } else {
      printf("nai");
    }
}