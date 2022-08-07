// 执行用时：16 ms, 在所有 C++ 提交中击败了91.37% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了84.26% 的用户

class Solution {
public:
    int n;

    pair<int, int> expand(const string& s , int lo, int hi) {
        while (lo >=0 && hi < n && lo <= hi && s[lo] == s[hi]) {
            --lo;
            ++hi;
        }
        return {lo+1, hi-1};
    }

    string longestPalindrome(string s) {
        n = s.size();
        int beg = 0, end = 0;
        
        for (int lo = 0; lo < n; ++ lo)  {

            auto [lo1, hi1] = expand(s, lo, lo);
            auto [lo2, hi2] = expand(s, lo, lo+1);

            if (hi1 - lo1 > end - beg) {
                end = hi1;
                beg = lo1;
            }
            if (hi2 - lo2 > end - beg) {
                end = hi2;
                beg = lo2;
            }
        
        }
        return s.substr(beg, end - beg + 1);
    }
};