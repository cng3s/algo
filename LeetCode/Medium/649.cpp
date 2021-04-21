// 执行用时：16 ms, 在所有 C++ 提交中击败了47.62% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了17.02% 的用户

class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> radiant, dire;
        int slen = senate.size();

        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') { radiant.emplace(i); }
            else { dire.emplace(i); }
        }

        while (!dire.empty() && !radiant.empty()) {
            if (dire.front() > radiant.front()) { radiant.emplace(radiant.front() + slen); }
            else { dire.emplace(dire.front() + slen); }
            radiant.pop();
            dire.pop();
        }

        return dire.empty() ? "Radiant" : "Dire";
    }
};