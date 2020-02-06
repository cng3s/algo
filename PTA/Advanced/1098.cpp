#pragma warning(disable : 4996)
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 101
int arr1[MAXN], heap[MAXN], arr2[MAXN], n;
int heap_idx = 1, arr1_idx = 1, arr2_idx = 1;

void adjust_down(int lo, int hi)
{
	int i = lo, j = lo * 2;
	while (j <= hi) {
		if (j + 1 <= hi && heap[j] < heap[j+1])
			j += 1;
		if (heap[i] >= heap[j])
			break;
		swap(heap[i], heap[j]);
		i = j;
		j = j * 2;
	}
}

bool is_arr_same(int a[], int b[])
{
	for (int i = 1; i <= n; ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

void show_arr(int a[])
{
	printf("%d", a[1]);
	for (int i = 2; i <= n; ++i)
		printf(" %d", a[i]);
	printf("\n");
}

void heap_sort()
{
	bool flag = false;
	int i;
	for (i = n/2; i >= 1; --i)
		adjust_down(i, n);
	for (i = n; i > 1; --i) {
		if (i != n && is_arr_same(heap, arr2))
			flag = true;
		swap(heap[i], heap[1]);
		adjust_down(1, i - 1);
		if (flag) {
			show_arr(heap);
			return;
		}
	}
}

bool insert_sort()
{
	bool flag = false;
	for (int i = 2; i <= n; ++i) {
		if (i != 2 && is_arr_same(arr1, arr2))
			flag = true;
		int e = arr1[i], j;
		for (j = i; j > 1 && arr1[j-1] > e; --j)
			arr1[j] = arr1[j-1];
		arr1[j] = e;
		if (flag)
			return true;
	}
	return false;
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &arr1[i]);
		heap[i] = arr1[i];
	}
	for (i = 1; i <= n; ++i)
		scanf("%d", &arr2[i]);

	if (insert_sort()) {
		printf("Insertion Sort\n");
		show_arr(arr1);
	} else {
		printf("Heap Sort\n");
		heap_sort();
	}

	return 0;
}