// 执行用时 :16 ms, 在所有 C++ 提交中击败了66.71% 的用户
// 内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> num_idx;
        vector<int> ans;
        int n = nums.size();

        for ( int i = 0; i < n; ++i ) { num_idx.insert( { nums[i], i } ); }

        for ( int i = 0; i < n; ++i ) {
            int num2 = target - nums[i];
            auto range = num_idx.equal_range(num2);
            for ( auto it = range.first; it != range.second; ++it ) {
                if ( it->first == num2 && it->second != i ) {
                    ans.push_back( i );
                    ans.push_back( it->second );
                    return ans;
                }
            }
        }
        return ans;
    }
};