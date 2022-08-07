// 执行用时：16 ms, 在所有 C++ 提交中击败了99.88% 的用户
// 内存消耗：12.7 MB, 在所有 C++ 提交中击败了49.60% 的用户

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) { return false; }
        int nmatrix = matrix.size(), colLeft = 0, colRight = matrix[0].size() - 1;
        
        
        for (int i = 0; i < nmatrix; ++i) {
            //cout << i << " ";
            colLeft = 0, colRight = matrix[0].size() - 1;
            while (colLeft <= colRight) {  
                int colMid = colLeft + (colRight - colLeft) / 2;
                //cout << "[" << colLeft << ", " << colRight << ", " << colMid << "]," ;
                if (matrix[i][colMid] > target) { colRight = colMid-1; }
                else if (matrix[i][colMid] < target) { colLeft = colMid+1; }
                else { return true; }
            }
            //cout << endl;
        }

        return false;
    }
};