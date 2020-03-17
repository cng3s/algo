//执行用时 :116 ms, 在所有 C++ 提交中击败了38.86% 的用户
//内存消耗 :27.4 MB, 在所有 C++ 提交中击败了34.24%的用户

// 这个答案慢在 map 查找、创建、插入 的开销上。可以尝试用哈希表优化这个。

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (chars.size() == 0) {
            return 0;
        }
        
        map<char, int> chs;
        int res = 0;
        for (auto it : chars) {
            ++chs[it];
        }

        for (auto word : words) {
            map<char, int> tmp;
            bool flag = true;
            for (auto it : word) {
                auto iter = tmp.find(it);
                if (iter != tmp.end()) {
                    if (iter->second > 0) {
                        --iter->second;
                    } else {
                        flag = false;
                    }
                } else if ((iter = chs.find(it)) != chs.end()) {
                    tmp.insert( {it, iter->second-1} );
                } else {
                    flag = false;
                }

                if (!flag) {
                    break;
                }
            }

            if (flag) {
                res += word.size();
            }
        }

        return res;
    }
};