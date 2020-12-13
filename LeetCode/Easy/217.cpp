// ִ����ʱ��72 ms, ������ C++ �ύ�л�����70.51% ���û�
// �ڴ����ģ�19.4 MB, ������ C++ �ύ�л�����51.73% ���û�
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (const auto n : nums) {
            if (s.find(n) != s.end()) { return true; }
            s.emplace(n);
        }
        return false;
    }
};