#pragma warning(disable : 4996)
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 1000
#define INF 0x3fffffff

int heap[MAXN];
int n;

void adjust_down(int low, int high)
{
	int i = low, j = i * 2;
	while (j <= high) {
		if (j + 1 <= high && heap[j + 1] > heap[j])
			j += 1;
		if (heap[i] >= heap[j])
			break;
		swap(heap[j], heap[i]);
		i = j;
		j = j * 2;
	}
}

void adjust_up(int low, int high)
{
	int i = high, j = i / 2;
	while (j >= low) {
		if (heap[j] >= heap[i])
			break;
		swap(heap[j], heap[i]);
		i = j;
		j = j / 2;
	}
}

void insert(int x)
{
	heap[++n] = x;
	adjust_up(1, n);
}

void create_heap()
{
	for (int i = n / 2; i >= 1; --i)
		adjust_down(i, n);
}

void sort_heap()
{
	create_heap();
	for (int i = n; i > 1; --i) {
		swap(heap[i], heap[1]);
		adjust_down(1, i - 1);
	}
}

void print_heap()
{
	for (int i = 1; i <= n; ++i)
		printf("%d ", heap[i]);
	printf("\n");
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", &heap[i]);
	create_heap();
	print_heap();
	sort_heap();
	print_heap();

	return 0;
}