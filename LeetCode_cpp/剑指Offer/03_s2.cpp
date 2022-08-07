class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int nnums = nums.size();
        vector<bool> mark(nnums);
        fill(mark.begin(), mark.end(), false);
        for (int i = 0; i < nnums; ++i) {
            if (!mark[nums[i]]) {
                mark[nums[i]] = true;
            }
            else {
                return nums[i];
            }
        }
        return -1;
    }
};