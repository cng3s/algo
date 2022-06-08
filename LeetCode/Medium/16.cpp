// 执行用时：12 ms, 在所有 C++ 提交中击败了85.75%的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了50.06%的用户

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = -1001;

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1, r = n - 1;
            // cout << nums[i] << ',' << nums[l] << ',' << nums[r] << endl;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == target) return sum;
                if (abs(target - sum) < abs(target - ans)) { 
                    // cout << nums[i] << ',' << nums[l] << ',' << nums[r] << ',' << sum << endl;
                   
                    ans = sum;
                } 

                if (sum < target) { 
                    int prev = nums[l];
                    while (l < n && l < r && prev == nums[++l]) ; 
                }
                else {
                    int prev = nums[r];
                    while (r > 0 && r > l && prev == nums[--r]) ;
                }
            }
        }

        return ans;
    }
};