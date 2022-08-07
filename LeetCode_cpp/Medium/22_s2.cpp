// 执行用时 :4 ms, 在所有 C++ 提交中击败了89.93% 的用户
// 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户
// bfs
//

class Solution {
private:
    typedef struct _entry {
        string s;
        int left, right;
        _entry( string str, int l, int r ) : s(str), left(l), right(r) {}
    } _entry;

public:
    vector<string> generateParenthesis(int n) {
        queue<_entry> q;
        vector<string> ans;
        _entry e( "(", 1, 0 );
        q.push(e);

        while ( !q.empty() ) {
            _entry cure = q.front();
            q.pop();

            if ( cure.left == n && cure.right == n ) {
                ans.push_back( cure.s );
                continue;
            }

            if ( cure.left > cure.right ) {
                _entry newe = cure;
                newe.s.push_back(')');
                ++newe.right;
                q.push(newe);
            } 
            if ( cure.left < n ) {
                _entry newe = cure;
                newe.s.push_back('(');
                ++newe.left;
                q.push(newe);
            }
        }
        return ans;
    }
};