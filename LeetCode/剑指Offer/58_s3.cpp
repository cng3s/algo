// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.7 MB, 在所有 C++ 提交中击败了25.93% 的用户

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.size()) + s.substr(0, n);
    }
};