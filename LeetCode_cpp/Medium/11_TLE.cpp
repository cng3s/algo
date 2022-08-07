// 49 / 50 个通过测试用例
// 超时
// 时间复杂度: O(nlogn)
//
class Solution {
private:
    int _water( vector<int>& height, int i, int j ) {
        int minheight = min( height[i], height[j] );
        return (j-i) * minheight;
    }

public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( height[i] == 0 ) { continue; }
            // 分为三种情况考虑：
            // 1. height[right] > height[left]: 此时h = height[left]，所以长度至少是 ceil(ans / h)
            // 2. height[right] == height[left]: 此时长度至少是ceil(ans / h)
            // 3. height[right] < height[left]: 此时长度肯定大于ceil(ans / h)
            // 通过这个我们就可以知道，最远可以从 ceil( ans/height[i] ) 开始遍历
            //
            int j = ceil( ans / height[i] ); // 尽可能挪到最远的距离开始遍历
            for ( ; j < n; ++j ) {
                ans = max( ans, _water(height, i, j) );
            }
        }

        return ans;
    }
};