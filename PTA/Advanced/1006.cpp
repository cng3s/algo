#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 记录最早进入和最迟离开的时分秒 以及 ID
unsigned earliest[3] = { UINT_MAX };
unsigned lastest[3] = { 0 };
string earlistestID, lastestID;

void split_time(string& str, vector<unsigned>& res)
{
	unsigned beg = 0, end = 0, len = str.size();
	string tmpstr;

	while (end + 1 != len) {
		if (str[end] == ':') {
			tmpstr = str.substr(beg, end - beg);
			res.push_back(stoul(tmpstr));
			beg = end + 1;
			end = beg;
		}
		end += 1;
	}
	tmpstr = str.substr(beg, end - beg + 1);
	res.push_back(stoul(tmpstr));
}

// 与earliest比较，如果比earliest早就更新earliest
inline bool compare_earliest_time(vector<unsigned> time)
{
	unsigned hour = min(time[0], earliest[0]),
		minute = min(time[1], earliest[1]), sec = min(time[2], earliest[2]);
	return (hour != earliest[0] || minute != earliest[1] || sec != earliest[2]);
}

inline bool compare_lastest_time(vector<unsigned> time)
{
	unsigned hour = max(time[0], lastest[0]),
		minute = max(time[1], lastest[1]), sec = max(time[2], lastest[2]);
	return (hour != lastest[0] || minute != lastest[1] || sec != lastest[2]);
}

int main()
{
	int N, i;
	string ID, signin, signout;
	vector<unsigned> timein, timeout;

	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> ID >> signin >> signout;
		timein.clear();
		timeout.clear();
		split_time(signin, timein);
		split_time(signout, timeout);
		if (compare_earliest_time(timein)) {
			earlistestID = ID;
			earliest[0] = timein[0];
			earliest[1] = timein[1];
			earliest[2] = timein[2];
		}
		if (compare_lastest_time(timeout)) {
			lastestID = ID;
			lastest[0] = timeout[0];
			lastest[1] = timeout[1];
			lastest[2] = timeout[2];
		}
	}

	cout << earlistestID << " " << lastestID;

	return 0;
}