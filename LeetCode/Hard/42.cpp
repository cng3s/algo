// 执行用时 :796 ms, 在所有 C++ 提交中击败了5.03% 的用户
// 内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, size = height.size();

        // 遍历所有元素，向左向右扫描，找到这个元素的左极高点和右极高点
        // 并计算出该元素可容纳的水量
        for ( int i = 1; i < size-1; ++i ) {
            int maxleft = 0, maxright = 0;
            for ( int j = i; j >= 0; --j ) {
                maxleft = max( height[j], maxleft );
            }
            for ( int j = i; j < size; ++j ) {
                maxright = max( height[j], maxright );
            }

            ans += min( maxleft, maxright ) - height[i];
        }

        return ans;
    }
};