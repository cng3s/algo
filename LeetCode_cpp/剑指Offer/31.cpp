// 执行用时：4 ms, 在所有 C++ 提交中击败了98.23% 的用户
// 内存消耗：14.8 MB, 在所有 C++ 提交中击败了37.33% 的用户

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int npushed = pushed.size(), npopped = popped.size();

        for (int i = 0, j = 0; i < npushed; ++i) {
            s.emplace(pushed[i]);
            while (j < npopped && !s.empty() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }

        return s.empty();
    }
};