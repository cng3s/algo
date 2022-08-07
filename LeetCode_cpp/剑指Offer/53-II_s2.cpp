// 执行用时：12 ms, 在所有 C++ 提交中击败了96.52% 的用户
// 内存消耗：16.7 MB, 在所有 C++ 提交中击败了67.09% 的用户

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            if (nums[mi] == mi) { lo = mi + 1; }
            else { hi = mi - 1;; }
        }

        return lo;
    }
};