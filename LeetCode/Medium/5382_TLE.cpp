// 超时
//

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> entity_ch{{"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'},
                                                {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'} };
        vector<string> entitys = {"&quot;","&apos;","&amp;","&gt;","&lt;","&frasl;"};
        
        for ( auto entity : entitys ) {
            size_t findidx;
            while ( (findidx = text.find(entity)) != string::npos ) {
                int len = entity.length();
                //cout << findidx << ", " << entity << ", " << len << ", " << text[findidx] << endl;
                text[findidx] = entity_ch.find(entity)->second;
                for ( int i = ++findidx; i < text.size()-len+1; ++i) { text[i] = text[i+len-1]; }
                text.erase(text.size()-len+1);
            }
        }
        
        return text;
    }
};