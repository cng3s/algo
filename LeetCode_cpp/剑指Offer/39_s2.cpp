// 执行用时：12 ms, 在所有 C++ 提交中击败了97.39% 的用户
// 内存消耗：18.3 MB, 在所有 C++ 提交中击败了27.92% 的用户
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, x = nums[0], nnums = nums.size();

        for (int i = 0; i < nnums; ++i) {
            if (nums[i] == x) ++vote;
            else --vote;
            if (vote == 0 && i < nnums -1 ) {
                x = nums[i+1];
            }
        }
        return x;
    }
};