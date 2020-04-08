// 执行用时 :8 ms, 在所有 C++ 提交中击败了68.64% 的用户
// 内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.size() == 0 ) {
            return 0;
        }
        int size = height.size(), ans = 0;
        vector<int> leftmaxs( size, 0 ), rightmaxs( size, 0 );
        leftmaxs[0] = height[0], rightmaxs[size-1] = height[size-1];

        for ( int i = 1; i < size; ++i ) {
            leftmaxs[i] = max( leftmaxs[i-1], height[i] );
        }
        for ( int i = size-2; i >= 0; --i ) {
            rightmaxs[i] = max( rightmaxs[i+1], height[i] );
        }

        for ( int i = 0; i < size; ++i ) {
            ans += min( leftmaxs[i], rightmaxs[i] ) - height[i];
        }

        return ans;
    }
};