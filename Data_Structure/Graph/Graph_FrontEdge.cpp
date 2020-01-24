// 前向星算法（链表法） 本质上就是使用数据维护的图链表法
// 其中head[i]就是图链表的dummyHead,next[i]记录i的所有出度在head数组中的索引值
// 既兼顾了数组的O(1)查找效率，又解决了矩阵图的空间浪费问题
#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

#define MAXV 510
#define INF 0x3fffffff
struct edge {
	int to, next, w; // 分别记录edge[i]某条出度的目的，下一条出度的索引值和边权重
} edges[MAXV];
int n, m, cnt = 0, head[MAXV];

inline void add_edge(int u, int v, int w)
{
	// 从1开始，本质就是链表插入操作
	edges[++cnt].next = head[u];
	edges[cnt].w = w;
	edges[cnt].to = v;
	head[u] = cnt;
}

void print_edges()
{
	int st;
	scanf("%d", &st);
	for (int i = head[st]; i != 0; i = edges[i].next)
		printf("Start: %d —— End: %d —— W: %d\n", st, edges[i].to, edges[i].w);
}

int main()
{
	int n, c1, c2;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &c1, &c2);
		add_edge(c1, c2, 1); // 这里不设置边权值,默认为1
	}
	print_edges();

	return 0;
}

// https://blog.csdn.net/Binary_Heap/article/details/78209086
// https://malash.me/200910/linked-forward-star/
// 逼站上