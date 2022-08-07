// 执行用时：280 ms, 在所有 C++ 提交中击败了7.74% 的用户
// 内存消耗：19.4 MB, 在所有 C++ 提交中击败了68.94% 的用户
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prev1, prev2, prev3 , sum = 0;
        vector<vector<int>> res;

        for (int i = 0; i < n-2; ++i) {

            if (i > 0) { // 去重 
                while (i < n - 2 && nums[i] == prev1) ++i;
            } 
            if (i >= n-2) break;
            prev1 = nums[i]; 


            // 当前的element>0,那么之后的也>0,结果不可能等于0
            if (nums[i] > 0) 
                break;
            sum = 0;
            prev2 = INT_MIN;
            for (int j = i + 1; j < n-1; ++j) {
                if (j > 1) { // 去重 
                    while (j < n - 1 && nums[j] == prev2) ++j;
                }

                if (j >= n-1) break;
                sum = nums[i] + nums[j];
                if (sum > 0) break; // 当前的element>0,那么之后的也>0,结果不可能等于0
                prev2 = nums[j]; 

                int val  = 0 - (nums[i] + nums[j]);
                bool ok = binary_search(nums.begin() + j + 1, nums .end(), val);
                if (ok )
                    res.emplace_back(vector({nums[i], nums[j], val}));
            }
        }

        return res;
    }
};