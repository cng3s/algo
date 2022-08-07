// 不用太计较，因为是调的库，所以是提交的人比较多导致击败率降低了
// 执行用时 :52 ms, 在所有 C++ 提交中击败了35.69% 的用户
// 内存消耗 :15.9 MB, 在所有 C++ 提交中击败了21.09%的用户

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};