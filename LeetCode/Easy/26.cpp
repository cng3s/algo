// 执行用时：4 ms, 在所有 C++ 提交中击败了97.48%的用户
// 内存消耗：17.9 MB, 在所有 C++ 提交中击败了71.97%的用户

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t n = nums.size();
        if (n <= 1) 
            return 1;

        for (auto beg = nums.begin(); beg != nums.end() ; ++beg) {
            auto end = (beg + 1);
            while (end != nums.end() && (*beg) == (*end)) { ++end; }
            --end;
            if (beg != end)
                beg = nums.erase(beg, end);
        }

        return nums.size();
    }
};