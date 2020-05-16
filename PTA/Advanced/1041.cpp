#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <climits>
#include <functional>

using namespace std;

int main()
{
    int N, tmp;
    scanf("%d", &N);

    map<int, pair<int, int>> num_record; // record: {cnt, first_index}
    for ( int i = 0; i < N; ++i ) {
        scanf("%d", &tmp);
        auto it = num_record.find(tmp);
        if ( it != num_record.end() ) { it->second.first += 1; }
        else { num_record.emplace( tmp, make_pair(1, i) ); }
    }

    int minidx = INT_MAX;
    map<int, pair<int, int>>::iterator mit;
    for ( map<int, pair<int, int>>::iterator it = num_record.begin();
        it != num_record.end(); ++it ) {
        if ( it->second.first == 1 and minidx > it->second.second ) {
            minidx = it->second.second;
            mit = it;
        }
    }

    if (minidx == INT_MAX) {
        printf("None");
    } else {
        printf("%d", mit->first);
    }
    
    return 0;
}