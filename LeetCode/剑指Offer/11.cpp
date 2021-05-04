// 执行用时：8 ms, 在所有 C++ 提交中击败了54.68% 的用户
// 内存消耗：11.6 MB, 在所有 C++ 提交中击败了95.44% 的用户

class Solution {
public:
    int minArray(vector<int>& numbers) {
        
        int nnumbers = numbers.size();
        if (nnumbers < 1) { return 0;}
        for (int i = 0; i < nnumbers; ++i) {
            if (numbers[i] < numbers[0]) { return numbers[i]; }
        }
        return numbers[0];
    }
};