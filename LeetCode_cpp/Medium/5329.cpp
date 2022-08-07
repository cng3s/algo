#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> tab;

public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size(), ans = 0;
        for (int i = 0; i < size;) {
            int cur = arr[i], cnt = 0;
            while (i < size && cur == arr[i]) {
                ++cnt;
                ++i;
            }
            tab.push_back(cnt);
        }
        sort(tab.begin(), tab.end(), greater<int>());
        size = floor(size / 2);
        for (int i = 0, sum = 0; i < tab.size(); ++i) {
            sum += tab[i];
            ++ans;
            if (sum >= size)
                break;
        }
        return ans;
    }
};

int main()
{
    vector<int> test = { 3,3,3,3,5,5,5,2,2,7 };
    Solution sol;
    cout << sol.minSetSize(test);

    return 0;
}