// 执行用时 :40 ms, 在所有 C++ 提交中击败了41.62% 的用户
// 内存消耗 :22.9 MB, 在所有 C++ 提交中击败了100.00%的用户
// 在线解法
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            sum = sum + nums[i];
            if ( sum > ans ) { ans = sum; }
            if ( sum < 0 ) { sum = 0; }
        }
        return ans;
    }
};