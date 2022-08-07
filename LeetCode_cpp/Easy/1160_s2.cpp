// 执行用时 :68 ms, 在所有 C++ 提交中击败了73.02% 的用户
// 内存消耗 :17.9 MB, 在所有 C++ 提交中击败了60.32%的用户

// 这次是使用了哈希表来做，速度快得多。


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (chars.size() == 0 || words.size() == 0) {
            return 0;
        }

        int alphabet[26], tmp[26], res = 0;
		// 记住：数组开辟后不会自动清0，所以你需要使用memset。第一次这里错了。
        memset(alphabet, 0, 26*sizeof(int));
        memset(tmp, 0, 26*sizeof(int));
        for (auto it : chars) {
            ++alphabet[it-97];
            ++tmp[it-97];
        }

        for (auto word : words) {
            bool success = true;
            for (auto it : word) {
                int idx = it-97;
                if (tmp[idx] > 0) {
                    --tmp[idx];
                } else {
                    success = false;
                    break;
                }
            }

            if (success) {
                res += word.size();
            }

            // reset tmp for next round
            for (int i = 0; i < 26; ++i) {
                tmp[i] = alphabet[i];
            }
        }
        return res;
    }
};




//执行用时 :64 ms, 在所有 C++ 提交中击败了83.29% 的用户
//内存消耗 :18.1 MB, 在所有 C++ 提交中击败了60.32%的用户
// 把memset 替换为 {0}， 略微提升
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (chars.size() == 0 || words.size() == 0) {
            return 0;
        }

        int alphabet[26] = { 0 }, tmp[26] = { 0 }, res = 0;
        for (auto it : chars) {
            ++alphabet[it-'a'];
            ++tmp[it-'a'];
        }

        for (auto word : words) {
            bool success = true;
            for (auto it : word) {
                int idx = it-97;
                if (tmp[idx] > 0) {
                    --tmp[idx];
                } else {
                    success = false;
                    break;
                }
            }

            if (success) {
                res += word.size();
            }

            // reset tmp for next round
            copy(begin(alphabet), end(alphabet), begin(tmp));
        }
        return res;
    }
};