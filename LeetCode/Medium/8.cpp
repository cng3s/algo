class Solution {
public:
    int myAtoi(string str) {

        // 判断字符串合法性
        if (str.size() == 0) {
            return 0;
        }

        int i = 0, end_flag = false, exp = 10, base = 1;
        for (i = 0; i < str.size() && !isdigit(str[i]) && !end_flag; ++i) {
            if (str[i] == ' ') {
                continue;
            } else if (str[i] == '+') {
                if (!isdigit(str[i+1])) {
                    end_flag = true;
                }
            } else if (str[i] == '-') {
                base = -1;
                if (!isdigit(str[i+1])) {
                    end_flag = true;
                }
            } else { // 非法字符
                end_flag = true;
            }
        }
        if (end_flag) {
            return 0;
        }

        // 组装字符串
        long res = 0;
        cout << "pos0: " << exp << ", " << base << endl;
        for (; i < str.size() && isdigit(str[i]); ++i) {
            res = res*exp + (str[i]-48)*base;
            if (res > INT_MAX) {
                return INT_MAX;
            } else if (res < INT_MIN) {
                return INT_MIN;
            }
        }
        return (int)res;
    }
};