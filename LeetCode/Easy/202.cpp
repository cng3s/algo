// 执行用时 :8 ms, 在所有 C++ 提交中击败了22.10% 的用户
// 内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;

        int sum;
        do {
            sum = 0;
            us.insert( n );
            while ( n != 0 ) {
                int bit = n % 10;
                n /= 10;
                sum += pow( bit, 2 );
            }
            if ( sum == 1 ) { return true; }
            n = sum;
        } while ( sum != 1 and us.find(sum) == us.end() );
        return false;
    }
};