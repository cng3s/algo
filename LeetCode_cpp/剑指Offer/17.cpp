// 执行用时：8 ms, 在所有 C++ 提交中击败了75.19% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了70.92% 的用户

class Solution {
public:
    vector<int> printNumbers(int n) {
        int upper = 1;
        while (n) { upper *= 10; --n; }
        vector<int> ans;

        for (int i = 1; i < upper; ++i) {
            ans.push_back(i);
        }
        return ans;
    }
};