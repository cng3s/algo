// 执行用时：40 ms, 在所有 C++ 提交中击败了38.33% 的用户
// 内存消耗：20.1 MB, 在所有 C++ 提交中击败了5.95% 的用户

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        for (int i = 0; i < arr.size(); ++i) { pq.emplace(arr[i]); }
        for (int i = 0; i < k; ++i) { ans.emplace_back(pq.top()); pq.pop(); }
        return ans;
    }
};