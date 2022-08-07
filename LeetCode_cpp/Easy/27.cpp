// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：8.5 MB, 在所有 C++ 提交中击败了73.60%的用户

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        
        auto begIt = nums.begin();
        while (begIt != nums.end() && (*begIt) != val) ++ begIt;

        if (begIt != nums.end()) {
            auto endIt = begIt;
            while (endIt != nums.end() && (*endIt) == val) ++ endIt;
            nums.erase(begIt, endIt);
        }

        return nums.size();
    }
};