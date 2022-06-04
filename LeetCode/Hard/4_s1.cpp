// 执行用时：24 ms, 在所有 C++ 提交中击败了76.22% 的用户
// 内存消耗：88.3 MB, 在所有 C++ 提交中击败了5.13% 的用户

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> nums3;
        for (size_t i = 0; i < nums1.size(); ++i)
            nums3.emplace_back(nums1[i]);
        for (size_t i = 0; i < nums2.size(); ++i)
            nums3.emplace_back(nums2[i]);
        sort(nums3.begin(), nums3.end());
        
        size_t ix = nums3.size() / 2;
        if (nums3.size() % 2 == 0)
            return (nums3[ix] + nums3[ix-1]) / 2;
        else 
            return nums3[ix];
    }
};