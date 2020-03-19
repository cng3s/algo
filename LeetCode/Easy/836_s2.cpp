//执行用时 :4 ms, 在所有 C++ 提交中击败了62.18% 的用户
//内存消耗 :10.2 MB, 在所有 C++ 提交中击败了7.14%的用户

class Solution {
public:
    // 对于不重合的情况取反，是个更简洁的做法
	// 但极为玄学的是，这个解法时间上居然慢得多。。。
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[3] <= rec2[1] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[0] >= rec2[2]);
    }
};