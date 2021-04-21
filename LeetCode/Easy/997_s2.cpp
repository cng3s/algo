// 执行用时：196 ms, 在所有 C++ 提交中击败了88.52%的用户
// 内存消耗：59.2 MB, 在所有 C++ 提交中击败了93.16%的用户

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int g[1001] = { 0 };
        
        for (int i = 0; i < trust.size(); ++i) {
            ++g[trust[i][1]];
            g[trust[i][0]] = INT_MIN;
        }

        for (int i = 1; i <= N; ++i) {
            if (g[i] == (N-1)) 
                return i;
        }


        return -1;
    }
};