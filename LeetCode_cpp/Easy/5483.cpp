class Solution {
public:
    string makeGood(string s) {
        string res{ s }, tmp;
        bool not_finish;
        do {
            not_finish = false;
            tmp = res, res = "";
            auto up_limit{ tmp.size() - 2 }, str_len = tmp.size();
            for (auto i = 0; i < str_len; ) {
                if (0 <= i && i <= up_limit
                    && (tmp[i] + 32 == tmp[i+1] || tmp[i] - 32 == tmp[i+1])) {
                    i += 2;
                    not_finish = true;
                }
                else {
                    res.push_back(tmp[i++]);
                }
            }
        } while (not_finish);
        
        return res;
    }
};