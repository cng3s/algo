// 执行用时：4 ms, 在所有 C++ 提交中击败了66.10% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了43.21% 的用户

class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        size_t cur = 0, n = s.size(), isNeg = false;

        while (s[cur] == ' ')  ++cur;
        if (s[cur] == '+') ++ cur;
        else if (s[cur] == '-') {
            isNeg = true; 
            ++cur;
        }

        if (!isdigit(s[cur])) 
            return 0;

        while (cur < n && s[cur] >= '0' && s[cur] <= '9') {
            ans *= 10;
            ans += static_cast<int>(s[cur] - '0');
            //cout << ans << endl;

            // step 5
            if (ans >  INT_MAX) {
                if (isNeg) ans = INT_MIN;
                else       ans = INT_MAX;
                break;
            }
            
            ++cur;
        }
        return isNeg ? -ans : ans;
    }
};