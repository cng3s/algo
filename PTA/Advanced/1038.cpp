#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	vector<string> strs;
	string tmp;
	int N;
	
	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		strs.emplace_back(tmp);
	}

	sort(strs.begin(), strs.end(),
		[](const string& lhs, const string& rhs) {
			return lhs + rhs < rhs + lhs;
		});


	tmp = "";
	for (const auto &str : strs) {
		tmp += str;
	}

	while (tmp.size() != 0 && tmp[0] == '0') {
		tmp.erase(tmp.begin());
	}
	
	if (tmp.size() == 0) { cout << "0" << endl; }
	else { cout << tmp << endl; }
	
	return 0;
}