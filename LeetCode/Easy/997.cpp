// 执行用时：180 ms, 在所有 C++ 提交中击败了96.25%的用户
// 内存消耗：59.2 MB, 在所有 C++ 提交中击败了97.49%的用户


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int g[1001] = { 0 };
        bool g2[1001];

        fill(g2, g2 + 1001, true);
        
        for (int i = 0; i < trust.size(); ++i) {
            ++g[trust[i][1]];
            g2[trust[i][0]] = false;
        }

        for (int i = 1; i <= N; ++i) {
            if (g[i] == (N-1) && g2[i] == true) 
                return i;
        }


        return -1;
    }
};