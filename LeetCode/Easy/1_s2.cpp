// 执行用时 :644 ms, 在所有 C++ 提交中击败了7.77% 的用户
// 内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for ( int i = 0; i < n; ++i ) {
            for ( int j = i+1; j < n; ++j ) {
                if ( nums[i] == target - nums[j] ) {
                    ans.push_back( i );
                    ans.push_back( j );
                    return ans;
                }
            }
        }
        return ans;
    }
};