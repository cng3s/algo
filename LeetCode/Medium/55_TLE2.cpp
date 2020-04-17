// BFS做法。垃圾
// 官方题解非常强
//
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0 ) { return false; }
        
        priority_queue<int> q; // idx
        unordered_map<int, bool> um;
        q.emplace( 0 );
        um.insert( {0, true} );

        while ( !q.empty() ) {
            int idx = q.top(), steps = nums[idx];
            q.pop();

            if ( idx + steps >= n-1 ) { return true; }
        
            for ( int i = idx+steps; i > idx; --i ) {
                if ( um.find(i) == um.end() ) {
                    q.emplace( i );
                    um.insert( {i, true} );
                }
            }
        }

        return false; 
    }
};