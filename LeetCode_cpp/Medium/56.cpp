// 执行用时 :24 ms, 在所有 C++ 提交中击败了95.28% 的用户
// 内存消耗 :10.5 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
private:
    // 注释掉的这个_cmp是一个BUG函数，是偏序而非全序的。在sort中使用它会出现问题。
    //static bool _cmp( vector<int>& v1, vector<int>& v2 ) { return ( v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] <= v2[1]) ); }
    static bool _cmp( vector<int>& v1, vector<int>& v2 ) { return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] < v2[1]; }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        if ( n == 0 ) { return ans; }

        sort( intervals.begin(), intervals.end(), _cmp );

        cout << n << endl;
        for ( int i = 0, j = 1; i < n; ) {
            int max_val = intervals[i][1];

            while ( j < n && intervals[j][0] <= max( max_val, intervals[j-1][1] ) ) {
                max_val = max( max_val, intervals[j][1] );
                ++j;
            }

            ans.push_back(vector<int>{intervals[i][0], max_val});
            i = j++;
        }

        return ans;
    }
};