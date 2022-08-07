// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了50.49% 的用户

class Solution {
public:
    int myAtoi(string s) {

        size_t curix = 0, n = s.size();
        bool isNeg = false;
        int cntop = 0;

        // step 1
        while (s[curix] == '+' || s[curix] == '-' || s[curix] == ' ') {
            if (s[curix] == '+' || s[curix] == '-') {
                ++cntop;
                if (!(s[curix + 1] >= '0' && s[curix + 1] <= '9')) return 0;
            }
            ++ curix;
        }
        if (cntop > 1) return 0;
        while (!(s[curix] >= '0' && s[curix] <= '9'))
            return 0;

        if (curix > 0 && s[curix-1] == '-') isNeg = true;

        long ans = 0;

        // step 3
        while (curix < n && s[curix] >= '0' && s[curix] <= '9') {
            ans *= 10;
            ans += static_cast<int>(s[curix] - '0');
            //cout << ans << endl;

            // step 5
            if (ans >  INT_MAX) {
                if (isNeg) ans = INT_MIN;
                else       ans = INT_MAX;
                break;
            }
            
            ++curix;
        }

        return isNeg ? (-ans) : ans;
    }
};