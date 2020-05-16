#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <climits>
#include <functional>

using namespace std;

int main()
{
    string line, tmp;
    getline(cin, line);
    map<size_t, long> strv_cnt;
    map<size_t, string> strv_str;
    hash<string> str_hash;

    for ( long i = 0; i < line.size(); ++i ) {
        if ( isalpha(line[i]) ) { tmp.push_back(tolower(line[i])); }
        else if ( isdigit(line[i]) ) { tmp.push_back(line[i]); }
        else {
            // cout << tmp << endl;
            size_t v = str_hash(tmp);
            auto mit = strv_cnt.find(v);
            if ( mit == strv_cnt.end() ) {
                strv_cnt.emplace(v, 1);
                strv_str.emplace(v, tmp);
            }
            else { mit->second += 1; }
            for ( ++i; not isalpha(line[i]) and not isdigit(line[i]); ++i ) ;
            tmp.clear();
            --i;
        }
    }

    map<size_t, long>::iterator res;
    long maxv = LONG_MIN;
    for ( map<size_t, long>::iterator it = strv_cnt.begin();
        it != strv_cnt.end(); ++it ) {
        if ( it->second > maxv ) { res = it; maxv = it->second; }
    }

    cout << strv_str[res->first] << " " << res->second;

    return 0;
}