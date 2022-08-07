class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> lens;
        int maxLen = INT_MIN, res = 0;

        for (const auto &rectangle : rectangles) {
            int len = min(rectangle[0], rectangle[1]);
            lens.emplace_back(len);
            maxLen = max(len, maxLen);
        }

        for (int i = 0; i < lens.size(); ++i) {
            if (lens[i] == maxLen) ++res;
        }

        return res;
    }
};
