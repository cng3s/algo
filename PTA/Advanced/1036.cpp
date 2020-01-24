/* 代码虽丑，但这题比较简单 如果想改好看，就用一个res queue来做for判断输出即可 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string name, ID;
	int grade;
	char gender;

	student(string nam, char gende, string id, int grad)
		: name(nam), grade(grad), ID(id), gender(gende) {}
};

int female = -1, male = -1; // 成绩最高的女孩和成绩最低的男孩在students中的位置

vector<student> students;

bool cmp(student stu1, student stu2)
{
	return stu1.grade > stu2.grade;
}

int main()
{
	int N, i, j, grad;
	string nam, ID;
	char gende;

	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> nam >> gende >> ID >> grad;
		student stu(nam, gende, ID, grad);
		students.push_back(stu);
	}
	sort(students.begin(), students.end(), cmp);

	bool f = 0, m = 0;
	for (i = 0, j = students.size() - 1; i < students.size() && j >= 0;) {
		if (!f && students[i].gender != 'F') {
			++i;
		} else {
			female = i;
			f = 1;
		}
		if (!m && students[j].gender != 'M') {
			--j;
		} else {
			male = j;
			m = 1;
		}
		if (f && m)
			break;
	}

	if (female != -1) {
		cout << students[i].name << " " << students[i].ID << endl;
	} else {
		cout << "Absent" << endl;
	}
	if (male != -1) {
		cout << students[j].name << " " << students[j].ID << endl;
	} else {
		cout << "Absent" << endl;
	}
	if (male != -1 && female != -1) {
		cout << students[i].grade - students[j].grade;
	} else {
		cout << "NA";
	}

	return 0;
}