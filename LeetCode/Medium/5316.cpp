#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words, retwords;
        vector<int> curs;
        stringstream ss;
        string tmp;
        int maxcol = 0;

        ss << s;
        while (ss >> tmp) {
            if (tmp.size() > maxcol) maxcol = tmp.size();
            words.push_back(tmp);
            curs.push_back(0);
        }
        retwords.resize(maxcol);
        for (int col = 0; col < maxcol; ++col) { // 按列扫描
            int spaces = 0;
            for (int i = 0; i < words.size(); ++i) { // 扫描每一个单词
                if (col >= words[i].size()) ++spaces;
                else {
                    for (int j = 0; j < spaces; ++j)
                        retwords[col].push_back(' ');
                    retwords[col].push_back(words[i][col]);
                    spaces = 0;
                }
            }
        }
        return retwords;
    }
};


int main()
{
    vector<string> res;
    Solution sol;
    res = sol.printVertically("CONTEST IS COMING");
    for (size_t i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}