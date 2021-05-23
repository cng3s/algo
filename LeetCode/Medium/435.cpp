// 执行用时：16 ms, 在所有 C++ 提交中击败了82.42% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了61.70% 的用户

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int nintervals = intervals.size();
        if (nintervals == 0) { return 0; }

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& lhs, const vector<int>& rhs) {
                 return lhs[1] < rhs[1];
             });

        int total = 0, prev = intervals[0][1];
        for (int i = 1; i < nintervals; ++i) {
            if (intervals[i][0] < prev) { ++total; }
            else { prev = intervals[i][1]; }
        }

        return total;
    }
};