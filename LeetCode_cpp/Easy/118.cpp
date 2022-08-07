// ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00% ���û�
// �ڴ����ģ�6.9 MB, ������ C++ �ύ�л�����14.79% ���û�

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