// 74 / 75 个通过测试用例
// 最后一个测试用例超时
//

class Solution {
private:
    int _n;

    bool _dfs( vector<int>& nums, int idx ) {
        int steps = nums[idx];
        
        if ( steps >= _n-idx-1 ) { return true; }
        if ( steps == 0 ) { return false; }

        for ( int i = steps; i > 0; --i ) {
            if ( _dfs(nums, idx+i) ) { return true; }
        }
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        _n = nums.size();
        return _dfs( nums, 0 ); 
    }
};