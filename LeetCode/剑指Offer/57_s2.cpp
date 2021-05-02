// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了99.02% 的用户

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> subans;

        for (int left = 1, right = 2; left < right;) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                subans.clear();
                for (int i = left; i <= right; ++i) {
                    subans.emplace_back(i);
                }
                ans.emplace_back(subans);
                ++left;
            }
            else if (sum < target) {
                ++right;
            }
            else if (sum > target) {
                ++left;
            }
        }

        return ans;
    }
};