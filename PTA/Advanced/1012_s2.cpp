
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr int maxn = 1e7+10;

struct Student {
    int id;
    int grade[4]; // A, C, M, E
} stu[2010];

char course[4] = { 'A', 'C', 'M', 'E' };
int Rank[maxn][4] = { 0 }; // Rank[id][0] ~ Rank[id][3] 对应4门课排名
int now;


int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (auto i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1],
                &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round(
            (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
    }

    for (now = 0; now < 4; ++now) { // 枚举 A\C\M\E 4个中的一个
        sort(stu, stu+n, [](const Student& lhs, const Student& rhs) 
            { return lhs.grade[now] > rhs.grade[now]; });
        Rank[stu[0].id][now] = 1;   // 排序后，将分数最高的设为1
        for (int i = 1; i < n; ++i) { // 对于剩下的考生
            // 如果与前面一名考生分数相同，则排名也相同
            if (stu[i].grade[now] == stu[i-1].grade[now])
                Rank[stu[i].id][now] = Rank[stu[i-1].id][now];       
            else
                Rank[stu[i].id][now] = i + 1;
        }
    }
    int query; // 查询考生排名
    for (auto i = 0; i < m; ++i) {
        scanf("%d", &query);
        if (Rank[query][0] == 0)
            printf("N/A\n");
        else {
            int k = 0; // 选出Rank[query][0~3]中最小的（rank值小，排名高）
            for (int j = 0; j < 4; ++j) {
                if (Rank[query][j] < Rank[query][k])
                    k = j;
            }
            printf("%d %c\n", Rank[query][k], course[k]);
        }
    }
}