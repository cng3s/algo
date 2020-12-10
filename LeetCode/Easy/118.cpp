// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了14.79% 的用户

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> v(i+1);
            v[0] = v[i] = 1;
            ret.emplace_back(v);

            for (int j = 1; j < i; ++j) {
                ret[i][j] = (ret[i-1][j-1] + ret[i-1][j]);
            }

        }
        return ret;
    }
};