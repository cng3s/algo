// 执行用时：188 ms, 在所有 C++ 提交中击败了96.42% 的用户
// 内存消耗：98.2 MB, 在所有 C++ 提交中击败了69.68% 的用户

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum < target) { ++l; }
            else if (sum > target) { --r; }
            else { return {nums[l], nums[r]}; }
        }
        return {};
    }
};