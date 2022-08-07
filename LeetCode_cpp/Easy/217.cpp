// 执行用时：72 ms, 在所有 C++ 提交中击败了70.51% 的用户
// 内存消耗：19.4 MB, 在所有 C++ 提交中击败了51.73% 的用户
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (const auto n : nums) {
            if (s.find(n) != s.end()) { return true; }
            s.emplace(n);
        }
        return false;
    }
};