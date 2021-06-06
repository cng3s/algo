// 执行用时: 4 ms
// 内存消耗: 11 MB

class Solution {
public:
    int n;
    
    bool isSameMat(const vector<vector<int>>& mat1, const vector<vector<int>> &mat2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                if (mat1[i][j] != mat2[i][j])
                    return false;
        }
        return true;
    }
    
    void rotateMat(vector<vector<int>>& mat) {
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
                res[j][n-i-1] = mat[i][j];
        }
        //printMat(res);

        mat = move(res);
    }
    
    void printMat(const vector<vector<int>>& mat) {
        cout << "[";
        for (int i = 0; i < n; ++i) {
            cout << "[";
            for (int j = 0; j < n; ++j)
                cout << mat[i][j] << ",";
            cout << "],";
        }
        cout << endl;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        
        for (int rotateTime = 0; rotateTime < 4; ++rotateTime) {
            bool ret = isSameMat(mat, target);
            if (ret)
                return true;
            rotateMat(mat);
        }
        
        return false;
    }
};