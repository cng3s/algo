// 执行用时：28 ms, 在所有 C++ 提交中击败了11.47% 的用户
// 内存消耗：16.7 MB, 在所有 C++ 提交中击败了21.82% 的用户


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int i = 0;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) { return i; }
        }

        return nums.size();
    }
};
