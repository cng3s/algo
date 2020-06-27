#pragma warning(disable : 4996)
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;

struct Student {
    int id;
    int scores[4]; // A/C/M/E
};
int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    vector<Student> stu(N); // 学生各科成绩
    unordered_map<int, vector<int>> stu_rank(M); // 学生各科名次
    char courseSymbol[4] = { 'A', 'C', 'M', 'E' };

    for (auto &cur : stu) {
        scanf("%d%d%d%d", &cur.id, &cur.scores[1],
            &cur.scores[2], &cur.scores[3]);
        cur.scores[0] = 
            round((cur.scores[1] + cur.scores[2] + cur.scores[3]) / 3.0) + 0.5;
        stu_rank.emplace(cur.id, vector<int>(4));
    }

    for (auto courseIx = 0; courseIx != 4; ++courseIx) {
        sort(stu.begin(), stu.end(), 
            [courseIx](const Student& lhs, const Student& rhs) -> bool {
                return lhs.scores[courseIx] > rhs.scores[courseIx];
            });
        auto it = stu_rank.find(stu[0].id);
        it->second[courseIx] = 1;  // 设置第一名
        for (auto studentIx = 1; studentIx != stu.size(); ++studentIx) {
            auto &curStudent = stu[studentIx], &preStudent = stu[studentIx-1];
            it = stu_rank.find(curStudent.id);
            if (curStudent.scores[courseIx] == preStudent.scores[courseIx])
                it->second[courseIx] = (stu_rank.find(preStudent.id)->second)[courseIx];
            else
                it->second[courseIx] = studentIx + 1;
        }
    }

    int query;
    for (auto queryIx = 0; queryIx < M; ++queryIx) {
        scanf("%d", &query);
        auto stuIt = stu_rank.find(query);
        if (stuIt == stu_rank.end()) {
            printf("N/A\n");
        } else {
            auto bestCourseIx = 0;
            for (auto courseIx = 1; courseIx < 4; ++courseIx) {
                if (stuIt->second[courseIx] < stuIt->second[bestCourseIx])
                    bestCourseIx = courseIx;
            }
            printf("%d %c\n", stuIt->second[bestCourseIx], courseSymbol[bestCourseIx]);
        }
    }
}