// 优化版本的merge_sort

#include <cstdio>
#include <algorithm>
using namespace std;

void insert_sort(int arr[], int lo, int hi)
{
	for (int i = lo+1; i <= hi; ++i) {
		int e = arr[i], j;
		for (j = i; j > 0 && arr[j-1] > e; --j)
			arr[j] = arr[j-1];
		arr[j] = e;
	}
}

void merge(int arr[], int lo, int mi, int hi)
{
    int *tmparr = new int[hi-lo+1], i, j, k;
    for (i = lo; i <= hi; ++i)
        tmparr[i-lo] = arr[i];

    for (i = lo, j = mi+1, k = lo; i <= mi && j <= hi; ++k) {
        if (tmparr[i-lo] < tmparr[j-lo]) {
            arr[k] = tmparr[i-lo];
            ++i;
        } else {
            arr[k] = tmparr[j-lo];
            ++j;
        }
    }
    while (i <= mi) { arr[k++] = tmparr[i-lo]; ++i; }
    while (j <= hi) { arr[k++] = tmparr[j-lo]; ++j; }
    delete[] tmparr;
}

void merge_sort(int arr[], int lo, int hi)
{
	if (hi - lo <= 15)
		insert_sort(arr, lo, hi);

    int mi = (lo>>1) + (hi>>1);
	//int mi = (lo+hi) / 2;
    merge_sort(arr, lo, mi);
    merge_sort(arr, mi+1, hi);
    if (arr[mi] > arr[mi+1])
        merge(arr, lo, mi, hi);
}

void merge_sort(int arr[], int n)
{
    merge_sort(arr, 0, n-1);
}

int main()
{
    int i, n = 10, *arr = new int[n];
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
	merge_sort(arr, 10);
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	return 0;
}