
// 执行用时：4 ms, 在所有 C++ 提交中击败了73.81% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了85.60% 的用户
class Solution {
public:
    int myAtoi(string str) {
        int i = 0, nstr = str.size();
        long res = 0;
        bool neg = false;
        while (str[i] == ' ') { ++i; }
        if (str[i] == '+') { ++i; }
        else if (str[i] == '-') { neg = true; ++i; }
        else if (!isdigit(str[i])) { return 0; }


        for (; i < nstr && isdigit(str[i]); ++i) {
            res = 10 * res;
            if (neg) { res += ('0' - str[i]); }
            else { res += str[i] - '0'; }
            //cout << '0' - str[i] << endl;
            //cout << res << " ";
            if (res > INT_MAX) { return INT_MAX; }
            if (res < INT_MIN) { return INT_MIN; }
        }
        return res;
    }
};