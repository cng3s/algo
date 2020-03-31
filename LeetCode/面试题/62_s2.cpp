// 超时解法
class Solution {
public:
    int lastRemaining(int n, int m) {
        
        list<int> ls;
        for (int i = 0; i < n; ++i) { ls.push_back(i); }

        auto it = ls.begin();
        while ( ls.size() > 1 ) {
            for ( int cnt = 1; cnt < m; ++cnt ) {
                if (it == ls.end()) { it = ls.begin(); }
                ++it;
            }
            if (it == ls.end()) { it = ls.begin(); }
            cout << *it << endl;
            it = ls.erase(it);
        }
        return it == ls.end() ? *(ls.begin()) : *it;
    }
};