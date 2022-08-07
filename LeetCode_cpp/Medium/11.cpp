// 执行用时 :16 ms, 在所有 C++ 提交中击败了85.90% 的用户
// 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户
// 双指针做法，特别快
// 时间复杂度O(n)，空间复杂度O(1)
//
class Solution {
private:
    int _water( vector<int>& height, int l, int r ) {
        int h = min( height[l], height[r] );
        return (r-l) * h;
    }
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1, l = 0;

        int ans = 0;
        while ( l < r ) {
            ans = max( ans, _water(height, l, r) );
            if ( height[l] < height[r] ) { ++l; }
            else { --r; }
        }
        return ans;
    }
};