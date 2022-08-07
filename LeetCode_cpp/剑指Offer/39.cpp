// 执行用时：24 ms, 在所有 C++ 提交中击败了42.96% 的用户
// 内存消耗：18.3 MB, 在所有 C++ 提交中击败了56.77% 的用户
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nnums = nums.size();
        unordered_map<int, int> counter;

        for (int i = 0; i < nnums; ++i) {
            ++counter[nums[i]];
            if (counter[nums[i]] > (nnums / 2))
                return nums[i];
        }
        return -1;
    }
};