// 执行用时：8 ms, 在所有 C++ 提交中击败了86.13% 的用户
// 内存消耗：14.8 MB, 在所有 C++ 提交中击败了88.70% 的用户

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int npushed = pushed.size(), npopped = popped.size();
        stack<int> s;

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