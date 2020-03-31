// 这道题是 约瑟夫问题 
// 基本思路是：反向思考。从最后一种情况开始逆推

// 因为是轮着数的，那么被删除的数字在上一轮中是第一个数字
// 也可以说，被删除的数字可以添加到该子序列的第一个
// 最后一轮中的数字位置为0，倒数第二轮有位置是个(0 + m) % seq_len ...



class Solution {
public:
    int lastRemaining(int n, int m) {

        int ret = 0;
        for (int i = 2; i <= n; ++i) {
            ret = (ret + m) % i;
        }
        return ret;
    }
};