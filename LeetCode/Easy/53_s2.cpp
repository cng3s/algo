// 执行用时 :48 ms, 在所有 C++ 提交中击败了25.58% 的用户
// 内存消耗 :23.1 MB, 在所有 C++ 提交中击败了100.00%的用户
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxidx = 0;

        for ( int i = 1; i < nums.size(); ++i ) {
            nums[i] = max( nums[i], nums[i]+nums[i-1] );
            if ( nums[i] > nums[maxidx]) { maxidx = i; }
        }
        return nums[maxidx];
    }
};