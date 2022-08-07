// 执行用时：8 ms, 在所有 C++ 提交中击败了80.51% 的用户
// 内存消耗：12.9 MB, 在所有 C++ 提交中击败了45.54% 的用户

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = 0;

        auto findIt  = lower_bound(nums.cbegin(), nums.cend(), target);
        while (findIt != nums.cend() && *findIt == target) { ++cnt; ++findIt; }
        return cnt;
    }
};