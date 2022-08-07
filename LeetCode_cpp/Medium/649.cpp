// ִ����ʱ��16 ms, ������ C++ �ύ�л�����47.62% ���û�
// �ڴ����ģ�8.1 MB, ������ C++ �ύ�л�����17.02% ���û�

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