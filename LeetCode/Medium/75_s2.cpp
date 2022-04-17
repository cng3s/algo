// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了41.22% 的用户
class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t ix_0 = -1; 
        size_t ix_2 = nums.size();
        for (size_t i = 0; i < ix_2; ) {
            switch (nums[i]) {
                case 0:
                    { swap(nums[++ix_0], nums[i++]); continue; }
                case 1:
                    { ++i; continue; }
                case 2:
                    { swap(nums[i], nums[--ix_2]); continue; }
            } 
        }
    }
};