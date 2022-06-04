// 执行用时：124 ms, 在所有 C++ 提交中击败了5.22% 的用户
// 内存消耗：42.3 MB, 在所有 C++ 提交中击败了7.22% 的用户

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> mat(numRows, vector<char>());
        int n = s.size(), curRow = 0, curCol = 0;
        string ans;

        for (int i = 0; i < n; ++i) {
            if (curRow == 0) {
                for (; i < n; ++i) {
                    if (curRow == numRows) {
                        --i;
                        --curRow;
                        if (curCol > 0) ++curCol;
                        break;
                    }
                    //cout << "a:" << curRow << ',' << curCol << ',' << i << ',' << s[i] << endl;
                    mat[curRow++].emplace_back(s[i]);

                }
            } else {
                // curRow == numRows-1
                assert(curRow == numRows-1);
                //cout << "d:" << curCol << endl;
                for (; i < n ; ++i) {
                    if (--curRow == 0) {
                        --i;
                        break;
                    }
                    
                    for (int k = numRows - 1; k >= 0; --k) {
                        mat[k].emplace_back(' ');
                    }
                    //cout << "b:" << curRow  << ',' << curCol+1 << ',' << i << ',' << s[i] << endl;
                    mat[curRow][++curCol] = s[i];
                    
                }
            }
        }

        for (const auto& e : mat) {
            for (auto c : e) {
                if (c == ' ')
                    continue; 
                   // cout << c ;
                ans.push_back(c);
            }
            cout << endl;
        }
        return ans;
    }
};