// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了12.20% 的用户

class Solution {
public:
  void sortColors(vector<int>& nums) {
    array<int, 3> cnt = { 0, 0 , 0 };
    size_t n = nums.size();
    for (size_t i = 0; i < n; ++i)
      cnt[nums[i]]++;
    int ix = 0;
    for (size_t i = 0; i < cnt[0]; ++i)
      nums[ix++] = 0;
    for (size_t i = 0; i < cnt[1]; ++i)
      nums[ix++] = 1;
    for (size_t i = 0; i < cnt[2]; ++i)
      nums[ix++] = 2;
  }
};