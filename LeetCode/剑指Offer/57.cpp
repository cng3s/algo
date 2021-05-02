// 执行用时：44 ms, 在所有 C++ 提交中击败了8.52% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了98.29% 的用户

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;


        vector<int> subans;
        for (int i = 1; i < target; ++i) {
            int sum = i;
            subans.clear();
            subans.emplace_back(i);

            for (int j = i + 1; j < target; ++j) {
                sum += j;
                subans.emplace_back(j);

                if (sum == target) {
                    ans.emplace_back(subans);
                }

                if (sum >= target) {
                    break;
                }
            }
        }


        return ans;
    }
};