// 执行用时 :28 ms, 在所有 C++ 提交中击败了92.94% 的用户
// 内存消耗 :22.7 MB, 在所有 C++ 提交中击败了100.00%的用户
// 使用哈希表的做法。效率比做排序高得多。

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> res;
        if (k == 0) {
            return res;
        }

        vector<int> hash(10001);
        fill(hash.begin(), hash.end(), 0);
        for (auto it : arr) {
            ++hash[it];
        }

        for (int i = 0; i < 10001; ++i) {
            if (hash[i] > 0) {
                if (hash[i] >= k) {
                    for (int j = 0;  j < k; ++j) {
                        res.push_back(i);
                    }
                    break;
                } else {
                    for (int j = 0; j < hash[i]; ++j) {
                        res.push_back(i);
                    }
                    k -= hash[i];
                }
            }
        }
        return res;
    }
};