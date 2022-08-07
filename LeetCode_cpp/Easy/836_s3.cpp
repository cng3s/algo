//执行用时 :4 ms, 在所有 C++ 提交中击败了62.18% 的用户
//内存消耗 :9.6 MB, 在所有 C++ 提交中击败了7.14%的用户

class Solution {
public:
    // 考虑是否有重叠矩形，即rec1和rec2是否有交集
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
            max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};