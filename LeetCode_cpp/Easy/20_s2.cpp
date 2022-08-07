// 表驱动法编写，这种写法在需要大量匹配的时候更有优势，不会造成代码爆炸
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool isValid(string s) {
        
        map<char, char> table;
        table[')'] = '(';
        table['}'] = '{';
        table[']'] = '[';

        stack<char> left;

        for ( auto ch : s ) {
            switch ( ch ) {
            case '(':
            case '{':
            case '[':
                left.push( ch );
                break;
            case '}':
            case ')':
            case ']':
                if ( left.empty() || left.top() != table[ch] ) { return false; }
                left.pop();
                break;
            }
        }
        return left.empty();
    }
};