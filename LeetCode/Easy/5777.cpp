// 执行用时: 224 ms
// 内存消耗: 80.9 MB

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        sort(nums.begin(), nums.end(),
            [](int lhs, int rhs) { return lhs > rhs; });
        
        for (int i = 0 ; i < n-1; ++i) {
            if (nums[i] != nums[i+1])
                ans += i + 1;
        }
        
        
        return ans;
    }
};