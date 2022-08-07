class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = INT_MIN;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            int cnt = 1, j;
            for (j = i+1; j < arr.size() && arr[j] == arr[i]; ++j) {
                ++cnt;
            }
            if (cnt == arr[i]) {
                res = arr[i];
            }
            i = j-1;
        }
        
        return res < 0 ? -1 : res;
    }
};