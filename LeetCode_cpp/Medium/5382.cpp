class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> entity_ch{{"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'},
                                                {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'} };
        vector<string> entitys = {"&quot;","&apos;","&amp;","&gt;","&lt;","&frasl;"};
        string ans;
        
        int i, prev;
        for ( i = 0, prev = 0; i < text.size(); ++i ) {
            if ( text[i] == '&' ) {
                //cout << "asdfj: " << text.substr(prev, i-prev) << endl;
                ans.append( text.substr(prev, i-prev) );
                int j;
                for ( j = i; j < i+7; ++j ) { if ( text[j] == ';' ) { break; } }
                string entity = text.substr(i, j-i+1);
                //cout << entity << endl;
                auto it = entity_ch.find( entity );
                if ( it != entity_ch.end() ) { ans.push_back( it->second );}
                else { ans.append(entity); }
                prev = j+1;
                i = j;
            }
        }
        string rest = text.substr(prev, text.size()-prev);
        //cout << "aaa: " << rest << endl;
        ans.append( rest );
        
        return ans;
    }
};