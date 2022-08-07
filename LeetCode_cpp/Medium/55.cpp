// 执行用时 :8 ms, 在所有 C++ 提交中击败了95.10% 的用户
// 内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxn = nums[0];

        for ( int i = 0; i <= maxn; ++i ) {
            maxn = max( maxn, i+nums[i] );
            if ( maxn >= n-1 ) { return true;}
        }
        return false;
    }
};