// 超时了的算法
class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<bool> vis(n);
        fill ( vis.begin(), vis.begin() + n, false );

        int vis_sz = n, idx, i = 0;
        while ( vis_sz > 0 ) { // while array vis has more than one element has not visited
            
            int cnt = 0;
            
            for ( ; cnt < m; ++i ) {
                idx = i % n;
                if ( vis[idx] == false ) {
                    ++cnt;
                }
            }

            vis[idx] = true;
            --vis_sz;
        }
        return idx;
    }
};