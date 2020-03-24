class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ret(index.size());
        int size = 0;
        for (int i = 0; i < index.size(); ++i) {
            int num = nums[i], idx = index[i];
            for (int j = size-1; j >= idx; --j) {
                ret[j+1] = ret[j];
            }
            ret[idx] = num;
            ++size;
        }
        
        return ret;
    }
};