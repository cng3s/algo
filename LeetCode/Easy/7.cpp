// 执行用时：4 ms, 在所有 C++ 提交中击败了49.96% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了92.92% 的用户
class Solution {
public:
    int reverse(int x) {
        
        long res = 0, base = 1;
        
        while (x) {
            int num = x % 10;
            x /= 10;
            
            res = res * 10 + num;
            
            if (res > INT_MAX || res < INT_MIN) {
                res = 0;
                break;
            }
        }

        return res;
    }
};