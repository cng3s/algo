#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	int bm[10] = { 0 };
	string num, tmpstr;
	bool CF = 0, YES = 1; // 进位标志(carry flag)
	unsigned bit, tmp; // 个位
	stringstream ss;

	cin >> num;
	for (int i = num.length() - 1; i >= 0; --i) {
		tmp = num[i] - '0';
		++bm[tmp];

		tmp *= 2;
		bit = tmp % 10;

		if (CF) {
			bit += 1;
			CF = 0;
		}

		ss << bit;
		ss >> tmpstr;
		num.replace(i, 1, tmpstr);
		ss.clear();

		// 手动乘法操作， 若大于10向高位进位
		if (tmp >= 10) {
			CF = 1;
		}	
	}
	if (tmp >= 10) {
		num = "1" + num;
		YES = 0;
	} else {
		for (auto iter = num.begin(); iter != num.end(); ++iter) {
			tmp = (*iter) - '0';
			--bm[tmp];
		}
		for (int i = 0; i < 10; ++i) {
			if (bm[i] != 0)
				YES = 0;
		}
	}
	

	cout << (YES ? "YES" : "NO") << endl << num;
	return 0;
}