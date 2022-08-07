// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了53.67% 的用户

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int joker = 0, nnums = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nnums; ++i) {
            if (nums[i] == 0) ++joker;
            else if (nums[i] > 0) break;
        }

        int prev = -1;
        for (int i = 0; i < nnums; ++i) {
            if (nums[i] != 0) {
                if (prev == -1) { prev = nums[i]; }
                else {
                    if (nums[i] != prev + 1)  {
                        if (joker > 0 && nums[i] != prev) {
                            joker = joker - (nums[i] - prev - 1);
                            if (joker < 0) return false;
                        }
                        else { return false; }
                    }
                    prev = nums[i];
                }
            }
        }

        return true;
    }
};