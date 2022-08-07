// 执行用时：4 ms, 在所有 C++ 提交中击败了92.07% 的用户
// 内存消耗：11.7 MB, 在所有 C++ 提交中击败了88.75% 的用户
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int lo = 0, hi = numbers.size() - 1;

        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (numbers[mi] < numbers[hi]) { hi = mi; } 
            else if (numbers[mi] > numbers[hi]) { lo = mi + 1; } 
            else { --hi; }
        }

        return numbers[lo];
    }
};