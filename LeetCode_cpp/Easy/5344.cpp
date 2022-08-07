#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
struct entry { int idx, num, tot; };
static bool cmp1(entry e1, entry e2) { return e1.num > e2.num; }

public:

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<entry> enums;
        vector<int> res;
        res.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            entry e;
            e.num = nums[i];
            e.idx = i;
            enums.push_back(e);
        }
        sort(enums.begin(), enums.end(), Solution().cmp1);
        for (int i = 0; i < enums.size(); ++i) {
            int j, k, tot;
            for (j = i + 1; j < enums.size() && enums[j].num == enums[i].num; j++) {
            }
            tot = enums.size() - j;
            for (k = i; k < j; ++k) {
                enums[k].tot = tot;
            }
            i = j-1;
        }
        for (auto it : enums) {
            res[it.idx] = it.tot;
        }
        return res;
    }
};


int main() {
    Solution sol;

    vector<int> nums = { 8, 1, 2, 2, 3 };
    vector<int> res = sol.smallerNumbersThanCurrent(nums);
    for (auto it : res) {
        cout << it << " ";
    }
    return 0;
}