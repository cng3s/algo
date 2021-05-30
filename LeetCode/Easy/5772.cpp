// 执行用时：4 ms, 在所有 C++ 提交中击败了50.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了100.00% 的用户

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
       int firstSum = firstWord[0] - 'a', secondSum = secondWord[0] - 'a', targetSum = targetWord[0] - 'a', base = 10;
        
        for (int i = 1; i < firstWord.size(); ++i) {
            firstSum *= base;
            firstSum += firstWord[i] - 'a';
        }
        
        for (int i = 1; i < secondWord.size(); ++i) {
            secondSum *= base;
            secondSum += secondWord[i] - 'a';
        }
        

        for (int i = 1; i < targetWord.size(); ++i) {
            targetSum *= base;
            targetSum += targetWord[i] - 'a';
        }
        
        return firstSum + secondSum == targetSum;
    }
};