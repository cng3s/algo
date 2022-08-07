// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :9.2 MB, 在所有 C++ 提交中击败了7.14%的用户

// 这个方法是判断各种重合的情况，比较蠢
// 反向思维思考这道题，有更简洁明了的解法。看看s2。

class Solution {
private:
    // rec1在左下，而rec2在右上，判断是否重叠
    // 满足: x22 > x11, x21 < x12, y12 > y21, y11 < y22
    bool _leftbottom_rightup(vector<int>& rec1, vector<int>& rec2) {
        return rec2[2] > rec1[0] && rec2[0] < rec1[2] && // x
            rec1[3] > rec2[1] && rec1[1] < rec2[3]; // y
    }

    // x21 < x12, x11 < x22, y11 < y21, y12 > y22
    bool _leftup_rightbottom(vector<int>& rec1, vector<int>& rec2) {
        return rec2[0] < rec1[1] && rec1[0] < rec2[2] && // x
            rec1[1] < rec2[1] && rec1[3] > rec2[3];
    }

public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return _leftbottom_rightup(rec1, rec2) || _leftbottom_rightup(rec2, rec1) || 
            _leftup_rightbottom(rec1, rec2) || _leftup_rightbottom(rec2, rec1);
    }
};