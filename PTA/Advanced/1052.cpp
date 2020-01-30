#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100000
struct node { int addr, data, next; bool valid; } ls[MAXN];
bool cmp(const struct node& e1, const struct node& e2)
{ return (!e1.valid || !e2.valid) ? e1.valid > e2.valid : e1.data < e2.data; }

int main()
{
        int n, beg, addr;
        scanf("%d%d", &n, &beg);
        for (int i = 0; i < n; ++i) {
                scanf("%d", &addr);
                scanf("%d%d", &ls[addr].data, &ls[addr].next);
                ls[addr].addr = addr;
        }

        int cnt = 0, cur = beg;
        while (cur != -1) {
                ls[cur].valid = true;
                ++cnt;
                cur = ls[cur].next;
        }
        if (cnt == 0) {
                printf("0 -1");
                return 0;
        }
        sort(ls, ls + MAXN, cmp);
        printf("%d %05d\n", cnt, ls[0].addr);
        for (int i = 0; i < cnt; ++i) {
                if (i != cnt - 1) {
                        printf("%05d %d %05d\n", ls[i].addr, ls[i].data, ls[i+1].addr);
                } else {
                        printf("%05d %d -1\n", ls[i].addr, ls[i].data);
                }
        }

        return 0;
}