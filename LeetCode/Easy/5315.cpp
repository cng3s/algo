#include <cstdio>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        int div = 10, cur = num, bit, res = 0;
        bool flag = 0;
        while (num / div >= 10) div *= 10;
        while (!flag && div != 0) {
            bit = cur / div;
            cur = cur % div;
            if (bit == 6) {
                flag = 1;
                bit = 9;
                if (div == 1) res += bit * div;
                else res += bit * div + cur;
            } else {
                res += bit * div;
            }
            div = div / 10;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int ret = sol.maximum69Number(9969);
    printf("%d", ret);
    return 0;
}