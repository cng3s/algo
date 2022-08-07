

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            if (nums[i] > 0) break;
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int prev_l = nums[l];
                    while (r > l && nums[++l] == prev_l) ;
                    int prev_r = nums[r];
                    while (r > l && nums[--r] == prev_r) ;
                } else if (sum > 0) {
                    int prev = nums[r];
                    while (r > l && nums[--r] == prev) ;
                } else if (sum < 0) {
                    int prev = nums[l];
                    while (l < r && nums[++l] == prev) ;
                }
            }
        }

        return ans;
    }
};