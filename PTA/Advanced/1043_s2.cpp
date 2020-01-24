/* 这个做法漂亮极了。重点在getpost中，使用先序遍历和数组下标得后序遍历。
 * https://www.liuchuo.net/archives/2153 */

#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> res;
bool ismirror = false;

void getpost(int root, int tail)
{
    if (root > tail)
        return;

    int i = root + 1, j = tail;
    if (ismirror) {
        while (i <= tail && seq[i] >= seq[root]) ++i;
        while (j > root && seq[j] < seq[root]) --j;
    } else {
        while (i <= tail && seq[i] < seq[root]) ++i;
        while (j > root && seq[j] >= seq[root]) --j;
    }

    if (i - j != 1)
        return;

    getpost(root + 1, j);
    getpost(i, tail);
    res.push_back(seq[root]);
}

int main()
{
    int N, i;

    scanf("%d", &N);
    seq.resize(N);
    for (i = 0; i < N; ++i)
        scanf("%d", &seq[i]);

    getpost(0, N - 1);
    if (res.size() != N) {
        ismirror = true;
        res.clear();
        getpost(0, N - 1);
    }
    if (res.size() != N) {
        printf("NO");
    } else {
        printf("YES\n%d", res[0]);
        for (i = 1; i < N; ++i)
            printf(" %d", res[i]);
    }

    return 0;
}