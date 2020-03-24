class Solution {
public:
    int massage(vector<int>& nums) {
        int len = nums.size();
        
        if (len == 0) {
            return 0;
        }

        int dp0 = 0, dp1 = nums[0], tdp0, tdp1;
        for (int i = 1; i < len; ++i) {
            tdp0 = max(dp0, dp1); // 不选择当前的预约,且选择该状态之前的最大预约时间
            tdp1 = dp0 + nums[i]; // 选择当前的预约

            dp0 = tdp0;
            dp1 = tdp1;
        }

        return max(dp0, dp1);
    }
};