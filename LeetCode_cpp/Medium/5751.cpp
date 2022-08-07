// 执行用时：204 ms, 在所有 C++ 提交中击败了50.00% 的用户
// 内存消耗：96 MB, 在所有 C++ 提交中击败了100.00% 的用户


class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int nnums1 = nums1.size(),  nnums2 = nums2.size();
        int i = 0, res = 0;

        for (int j = 0; j < nnums2; ++j) {
            while (i < nnums1 && nums1[i] > nums2[j]) { ++i; }
            if (i < nnums1) { res = max(res, j - i); }
        }

        return res;
    }
};