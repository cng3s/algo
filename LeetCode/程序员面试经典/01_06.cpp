//执行用时 :12 ms, 在所有 C++ 提交中击败了86.17% 的用户
//内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    string compressString(string s) {
        string ret;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size()) {
                ret += c + to_string(cnt);
                break;
            } else if (s[i] != c) {
                ret += c + to_string(cnt);
                cnt = 1;
                c = s[i];
            } else {
                ++cnt;
            }
        }

        return ret.size() < s.size() ? ret : s;
    }
};

class Solution2 {
public:
    string compressString(string s) {
        string ret;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != c) {
                ret += c + to_string(cnt);
                cnt = 1;
                c = s[i];
            } else {
                ++cnt;
            }
        }
        ret += c + to_string(cnt);
        return ret.size() < s.size() ? ret : s;
    }
};