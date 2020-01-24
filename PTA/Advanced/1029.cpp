#pragma warning(disable : 4996)
/* https://www.liuchuo.net/archives/2248
 * 很厉害的在线处理方法。
 * 设midpos是中位数位置。输入第一个序列各数字n到数组中后，逐个输入第二个序列数字m。
 * count统计读入数字的总个数，若count == midpos则该数是中位数。
 * m和第一个序列的数字n比较，若m或n应在midpos位置上则它就是中位数。
 * 如果m或n不应该插入在midpos上，则继续向后走找到应该在midpos上的那个数输出。O(n)搞定。
 * */

#include <cstdio>
#include <climits>
using namespace std;

#define CAPCITY 200001
long k[CAPCITY];

int main()
{
    int N1, N2, i, j = 0, count = 0, midpos;
    long tmp;

	scanf("%d", &N1);
	for (i = 0; i < N1; ++i)
        scanf("%ld", &k[i]);

    scanf("%d", &N2);
    midpos = (N1 + N2 - 1) / 2;
    k[N1] = LONG_MAX;
    for (i = 0; i < N2; ++i) {
        scanf("%ld", &tmp);
        while (tmp > k[j]) {
            if (count == midpos) {
                printf("%ld", k[j]);
                return 0;
            }
            ++count;
            ++j;
        }
        if (count == midpos) {
            printf("%ld", tmp);
            return 0;
        }
        ++count;
    }

    // 此时中位数不在S2序列而在S1剩余的序列中
    while (j < N1) {
        if (count == midpos) {
            printf("%ld", k[j]);
            break;
        }
        ++count;
        ++j;
    }

    return 0;
}

/* 这段代码还是非常难写的，必须清楚count, midpos, j更新顺序，以及初始赋值。 */