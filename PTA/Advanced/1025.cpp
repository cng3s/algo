#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Testee {
	string id;
	unsigned score;
	unsigned local_num;
	unsigned local_rank;
} tst[30005];

bool mycmp1(Testee t1, Testee t2)
{
	if (t1.score != t2.score)
		return t1.score > t2.score;
	else
		return t1.id < t2.id;
}

int main()
{
	unsigned N, K, total = 0;
	unsigned i, j;

	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> K;
		for (j = 0; j < K; ++j) {
			cin >> tst[total].id >> tst[total].score;
			tst[total++].local_num = i + 1;
		}
		sort(tst + total - K, tst + total, mycmp1); // 对当前考场学生排序

		// 确定考生的local_rank
		tst[total - K].local_rank = 1;
		for (j = total - K + 1; j < total; ++j) {
			if (tst[j].score == tst[j - 1].score) {
				tst[j].local_rank = tst[j - 1].local_rank;
			} else {
				tst[j].local_rank = j + 1 - (total - K);
			}
		}
	}

	// 对全部考场学生进行排序
	sort(tst, tst + total, mycmp1);

	unsigned rank = 1;
	cout << total << endl << tst[0].id << " " << 1 << " "
		<< tst[0].local_num << " " << tst[0].local_rank;
	for (i = 1; i < total; ++i) {
		if (tst[i].score != tst[i - 1].score) {
			rank = i + 1;
		}
		cout << endl << tst[i].id << " " << rank << " "
			<< tst[i].local_num << " " << tst[i].local_rank;
	}

	return 0;
}
