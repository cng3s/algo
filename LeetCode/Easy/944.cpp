class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        if (strs.empty() || strs[0].empty()) {
            return 0;
        }

        int strLength = strs[0].size(), nstrs = strs.size(), res = 0;
        for (int i = 0; i < strLength; ++i) {
            for (int j = 1; j < nstrs; ++j) {
                if (strs[j][i] < strs[j-1][i]) {
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};