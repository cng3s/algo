// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;

        for ( auto ch : s ) {
            switch ( ch ) {
            case '(':
            case '{':
            case '[':
                left.push( ch );
                break;
            
            case '}':
                if ( left.empty() || left.top() != '{' ) { return false; }
                else { left.pop(); break; }
            case ')':
                if ( left.empty() || left.top() != '(' ) { return false; }
                else { left.pop(); break; }
            case ']':
                if ( left.empty() || left.top() != '[' ) { return false; }
                else { left.pop(); break; }
            }
        }
        return left.empty();
    }
};