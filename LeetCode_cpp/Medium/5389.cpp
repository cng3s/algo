// 执行用时 :492 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :69 MB, 在所有 C++ 提交中击败了100.00%的用户
//
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        int n = orders.size();
        if ( n ==  0 )      { return ans; }
        
        map<int, map<string, int>> table_orders;
        set<string> foods;
        unordered_set<string> us;
        
        
        for ( int i = 0; i < n; ++i ) {           
            vector<string> order(orders[i]);
            
            // 将顾客订单添加到记录中
            int idx = stoi( order[1] );
            auto tableIt = table_orders.find( idx );
            if ( tableIt == table_orders.end() ) {
                table_orders.emplace( idx, map<string, int>() );
                tableIt = table_orders.find( idx );
            }
            
            map<string, int> &myorders = tableIt->second;
            auto orderIt = myorders.find( order[2] );
            if ( orderIt == myorders.end() )    { myorders.emplace(order[2], 1); }
            else                                { ++orderIt->second; }
            
            auto foodIt = us.find( order[2] );
            if ( foodIt == us.end() ) { foods.emplace( order[2] ); us.emplace( order[2] ); }
        }
        
        
        vector<string> opions;
        opions.emplace_back("Table");
        for ( auto food : foods )     { opions.emplace_back(food); }
        ans.emplace_back( opions );
        
        for ( auto record : table_orders ) {
            vector<string> res;
            res.emplace_back( to_string(record.first) );
            
            for ( auto food : foods ) {
                int foodnum = 0;
                auto it = record.second.find( food );
                if ( it != record.second.end() )   { foodnum = it->second; }
                res.emplace_back( to_string(foodnum) );
            }
            ans.emplace_back( res );
        }
        
        return ans;
    }
};