// 执行用时：8 ms, 在所有 C++ 提交中击败了77.74% 的用户
// 内存消耗：5.6 MB, 在所有 C++ 提交中击败了95.37% 的用户
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l = 0, r  = s.size() - 1;

        while (l < r) {
            if (s[l++] != s[r--]) return false;
            
        }
        return true;
    }
};