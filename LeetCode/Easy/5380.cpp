class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        unordered_map<string, int> st;
        hash<string> str_hash;
        
        for ( int i = 0; i < n; ++i ) {
            for ( int j = i+1; j < n; ++j ) {
                if ( st.find(words[j]) == st.end() && words[i].find(words[j]) != string::npos ) { ans.push_back(words[j]); st.insert( {words[j], 1} ); }
                else if ( st.find(words[i]) == st.end() && words[j].find(words[i]) != string::npos ) { ans.push_back(words[i]); st.insert( {words[i], 1} ); }
            }
        }
        return ans;
    }
};