// 执行用时：28 ms, 在所有 C++ 提交中击败了87.36% 的用户
// 内存消耗：18.2 MB, 在所有 C++ 提交中击败了89.23% 的用户

class Solution {

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() < k) { return arr; }
        sort(arr.begin(), arr.end());
        return vector(arr.cbegin(), arr.cbegin() + k);
    }
};