// 执行用时：20 ms, 在所有 C++ 提交中击败了81.79% 的用户
// 内存消耗：17.7 MB, 在所有 C++ 提交中击败了33.80% 的用户

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int nnums = nums.size(), l = 0, r = nnums - 1;

        while (l < r) {
            while (l < r && nums[l] % 2 != 0) { ++l; }
            while (l < r) {
                if (nums[r] % 2 != 0) {
                    //cout << nums[l] << ", " << nums[r] << endl;
                    swap(nums[l++], nums[r]);
                    break;
                }
                --r;
            }
        }
        return nums;
    }
};