#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

typedef struct student {
    string name, id;
    int grade;
} student;

int N, grade1, grade2;

int main()
{
    scanf("%d", &N);
    map<int, student> grade_stu;
    for ( int i = 0; i < N; ++i ) {
        student stu;
        cin >> stu.name >> stu.id >> stu.grade;
        grade_stu.emplace(stu.grade, stu);
    }
    scanf("%d%d", &grade1, &grade2);

    stack<student*> s;
    for ( auto low = grade_stu.lower_bound(grade1); low != grade_stu.end(); ++low ) {
        if ( low->first > grade2 )  { break; }
        s.push(&low->second);
    }

    if ( s.empty() ) {
        cout << "NONE";
    } else {
        while ( !s.empty() ) {
            student* cur = s.top();
            s.pop();
            cout << cur->name << " " << cur->id << endl;
        }
    }

    return 0;
}
