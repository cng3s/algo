// 执行用时 :4 ms, 在所有 C++ 提交中击败了68.35% 的用户
// 内存消耗 :7.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        vector<vector<int>> newmat( N, vector<int>(N) );

        for ( int i = 0; i < N; ++i ) {
            for ( int j = 0; j < N; ++j ) {
                newmat[j][N-i-1] = matrix[i][j];
            }
        }

        matrix = newmat;
    }
};