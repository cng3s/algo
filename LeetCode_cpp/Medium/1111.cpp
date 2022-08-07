// 执行用时 :8 ms, 在所有 C++ 提交中击败了51.32% 的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
// 这道题有点恶心人。
// 首先题意难以理解，其实是说任意两个括号都可以配对，要求最小的嵌套深度
// 我是按照官方题解第一种做的

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<pair<char, int>> left;
        vector<int> ret;

        for ( auto ch : seq ) {
            switch ( ch ) {
            case '(': {
                int val = left.empty() ? 1 : left.top().second+1;
                left.push( {'(', val} );
                ret.push_back( (val % 2 == 0 ? 1 : 0) );
                break;
            }
            case ')': { // 题目中已经说明seq满足有效括号字符串，所以不需要判断合法性
                ret.push_back( (left.top().second % 2 == 0 ? 1 : 0) );
                left.pop();
                break;
            }
            }
        }

        return ret;
    }
};