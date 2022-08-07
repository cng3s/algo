class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            int min = matrix[i][0], idx = 0, flag = 1; 
            for (int j = 1; j < n; ++j) { // find minimum-number's index  in row:i
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    idx = j;
                }
            }
            for (int k = 0; k < m; ++k) {
                if (matrix[k][idx] > min) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                res.push_back(min);
            }
        }
        return res;
    }
};