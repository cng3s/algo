// 执行用时：4 ms, 在所有 C++ 提交中击败了33.33% 的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了66.67% 的用户

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ns = s.size(), oneCnt = 0, zeroCnt = 0;
        
        for (int i = 0; i < ns; ) {
            int cnt = 0;
            if (s[i] == '1') {
                while (i < ns && s[i] == '1') { ++cnt; ++i; }
                oneCnt = max(oneCnt, cnt);
            }
            else {
                while (i < ns && s[i] == '0') { ++cnt; ++ i; }
                zeroCnt = max(zeroCnt, cnt);
            }
        }
        //cout << oneCnt << ", " << zeroCnt; 
        return oneCnt > zeroCnt; 
    }
};