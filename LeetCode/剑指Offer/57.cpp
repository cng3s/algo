// 执行用时：248 ms, 在所有 C++ 提交中击败了36.60% 的用户
// 内存消耗：98.1 MB, 在所有 C++ 提交中击败了87.97% 的用户

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int nnums = nums.size();

        for (auto numsIt = nums.cbegin(); numsIt != nums.cend(); ++numsIt) {
            int sum = *numsIt, left = target - sum;
            if (sum > target / 2) { break; }
            auto anotherIt = lower_bound(numsIt, nums.cend(), target - sum);
            
            if (anotherIt != nums.end() && *anotherIt == left) {
                ans.push_back(*numsIt);
                ans.push_back(*anotherIt);
                break;
            }
        }
        return ans;
    }
};