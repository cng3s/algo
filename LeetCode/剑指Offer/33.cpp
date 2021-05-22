// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了74.67% 的用户
class Solution {
public:
    bool veritfy(vector<int>& postorder, int lo, int hi) {
        if (lo >= hi) { return true; }

        int p = lo;
        while (postorder[p] < postorder[hi]) { ++p; }
        int k = p;
        while (postorder[p] > postorder[hi]) { ++p; }
        return p == hi && veritfy(postorder, lo, k-1) && veritfy(postorder, k, hi-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return veritfy(postorder, 0, postorder.size() - 1);
    }
};