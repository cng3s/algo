// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了26.03%的用户

class Solution {
public:
    vector<string> res;

    void makeResult(const vector<string>& strs, string &tmp, int strsIx) {
        if (strsIx == strs.size()) {
            if (strs.size() != 0)
                res.emplace_back(tmp);
            return;
        } else {
            int cnt = 0;
            for (const auto c : strs[strsIx]) {
                tmp.push_back(c);
                makeResult(strs, tmp, strsIx+1);
                tmp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        map<int, string> tbl = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        vector<string> strs ;
        for (const auto c : digits) {
            if (c >= '2' && c <= '9') strs.emplace_back(tbl[c - '0']);
        }


        string tmp;
        makeResult(strs, tmp, 0);

        return res;
    }
};