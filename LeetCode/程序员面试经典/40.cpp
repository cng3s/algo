// 执行用时: 36 ms
// 内存消耗：20.8 MB

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
};