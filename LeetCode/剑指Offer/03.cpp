class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int nnums = nums.size();
        for (int i = 0; i < nnums; ++i) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                else if (i > 0 && nums[i] != 0) {
                    break;
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};