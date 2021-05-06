// 执行用时：4 ms, 在所有 C++ 提交中击败了89.81% 的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了47.66% 的用户

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int ns = s.size();
        
        for (int right = ns - 1, left = ns - 1; left >= 0 && left <= right;) {
            while (left >= 0 && s[left] == ' ') { --left; }
            if (left < 0) { break; }
            right = left;

            while (left >= 0 && s[left] != ' ') { --left; }
            ++left;
            //cout << left << ", " << right - left << ", " << s.substr(left, right - left);
            ans.append(s.substr(left, right - left + 1) + " "); 
            --left;
        }
        if (!ans.empty())
            ans.pop_back();
        
        return ans;
    }
};