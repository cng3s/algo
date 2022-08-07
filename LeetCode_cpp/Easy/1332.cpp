#include <string>
#include <iostream>
using namespace std;

class Solution {
public:

	int removePalindromeSub(string s) {
		if (s.empty()) return 0;
		int i, j;
		for (i = 0, j = s.size() - 1; i < j; ++i, --j) {
			if (s[i] != s[j])
				break;
		}
		return i >= j ? 1 : 2;
	}
};


int main()
{
	Solution sol;
	string str = "bbaabaaa";

	cout << sol.removePalindromeSub(str);

	return 0;
}
