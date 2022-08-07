// 执行用时 :888 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :100.3 MB, 在所有 C++ 提交中击败了100.00%的用户
//

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n = increase.size(), m = requirements.size();
        vector<int> ans( m, -1 );
        multimap<int, int> sum_idx;
        
        for ( int i = 0; i < n; ++i ) {
            if (i > 0 )
                increase[i][0] += increase[i-1][0], increase[i][1] += increase[i-1][1], increase[i][2] += increase[i-1][2];
            int sum = increase[i][0]+increase[i][1]+increase[i][2];
            sum_idx.emplace( sum, i );
        }
        
        for ( int i = 0; i < m; ++i ) {
            int sum = requirements[i][0]+requirements[i][1]+requirements[i][2];
            if ( sum == 0 ) { ans[i] = 0; continue; }
            for ( auto it = sum_idx.lower_bound(sum); it != sum_idx.end(); ++it ) {
                int idx = it->second;
                if (increase[idx][0] >= requirements[i][0] and 
                    increase[idx][1] >= requirements[i][1] and 
                    increase[idx][2] >= requirements[i][2]) {
                    ans[i] = idx+1;
                    break;
                }
            }
        }
        
        return ans;
    }
};