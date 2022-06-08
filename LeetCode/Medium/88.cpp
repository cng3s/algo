// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了90.59%的用户


class Solution {
public:
    vector<string> res;

    // n: 还剩下可以使用的右括号个数
    void dfs(stack<char> &st, int n, string &tmp) {
        if (st.size() == n) {
            res.emplace_back(tmp + string(n, ')'));
            return;
        }


        st.push('(');
        tmp.push_back('(');
        dfs(st, n, tmp);
        tmp.pop_back();
        st.pop();

        if (n > 0 && !st.empty()) {
            tmp.push_back(')');
            st.pop();
            dfs(st, n-1, tmp);
            st.push('(');
            tmp.pop_back();
        } 
    }

    vector<string> generateParenthesis(int n) {
        
        stack<char> st;
        string tmp;
        dfs(st, n, tmp);
        return res;
    }
};