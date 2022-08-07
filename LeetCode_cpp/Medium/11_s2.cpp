// 执行用时：72 ms, 在所有 C++ 提交中击败了67.95% 的用户
// 内存消耗：57.6 MB, 在所有 C++ 提交中击败了37.59% 的用户

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans= INT_MIN;
        while (l < r) {
            int h = std::min(height[l], height[r]);
            ans = std::max(ans, h * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return ans;
    }
};