// 执行用时：8 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.6 MB, 在所有 C++ 提交中击败了66.67% 的用户

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        if (logs.size() == 0) { return 0; }
        
        int arr[105], nlogs = logs.size(), nsublog = logs[0].size();
        fill(arr, arr + 105, 0);
        
        for (const auto& log : logs) {
            int begYear = log[0] % 1950, endYear = log[1] % 1950;
            //cout << begYear << ", " << endYear << endl;
            while (begYear < endYear) { ++arr[begYear]; begYear++; }
        }
        
        //for (int i = 0; i < 105; ++i) { cout << "[" << i + 1950 << ", " << arr[i] << "] "; }
        
        int ans = 0, maxCnt = INT_MIN;
        for (int i = 0; i < 105; ++i) {
            if (arr[i] > maxCnt) { maxCnt = arr[i]; ans = i; }
        }
        
        return ans + 1950;
    }
};