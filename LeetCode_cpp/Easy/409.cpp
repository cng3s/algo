class Solution {
public:
    int longestPalindrome(string s) {
        int alpha[52] = { 0 };
        int res = 0;
        for (auto it : s) {
            if (it <= 'Z' && it >= 'A') {
                ++alpha[it-'A'+26];
            } else {
                ++alpha[it-'a'];
            }
        }
        bool odd = false;
        for (int i = 0; i < 52; ++i) {
            if (alpha[i] % 2 == 0) {
                res += alpha[i];
            } else {
                res += alpha[i]-1;
                odd = true;
            }
        }
        return odd ? res + 1 : res;
    }
};