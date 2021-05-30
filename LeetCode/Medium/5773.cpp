// 执行用时：72 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：34.1 MB, 在所有 C++ 提交中击败了100.00% 的用户

class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] == '-') {
            for (int i = 1; i < n.size() ; ++i) {
                if (n[i] - '0' <= x) { continue; }
                return n.substr(0, i) + to_string(x) + n.substr(i, n.size() - i);
            }
        } else {
            for (int i = 0; i < n.size() ; ++i) {
                if (n[i] - '0' >= x) { continue; }
                return n.substr(0, i) + to_string(x) + n.substr(i, n.size()  - i);
            }
        }
        return n.substr(0, n.size()) + to_string(x);
    }
};