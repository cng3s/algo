// 执行用时：48 ms, 在所有 C++ 提交中击败了47.07% 的用户
// 内存消耗：18.2 MB, 在所有 C++ 提交中击败了10.49% 的用户

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> table;
        int nnums = nums.size();

        for (int i = 0; i < nnums; ++i) {
            table[nums[i]] ++;
        }

        for (auto [num, time] : table) {
            if (time == 1) { return num; }
        }

        return -1;
    }
};