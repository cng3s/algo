// 执行用时：24 ms, 在所有 C++ 提交中击败了67.99% 的用户
// 内存消耗：22.2 MB, 在所有 C++ 提交中击败了98.17% 的用户

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxv = INT_MIN, curv = 0, nnums = nums.size();

        for (int i = 0; i < nnums; ++i) {
            curv = curv + nums[i];
            maxv = max(maxv, curv);
            if (curv < 0) { curv = 0; }
        }
        return maxv;
    }
};