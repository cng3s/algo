#pragma warning(disable : 4996)
#include <cstdio>

template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
    int *aux = new int[r-l+1];
    for (int i = l; i <= r; ++i)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1, k = l;
    for (; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j-l];
            ++j;
        }
        else if (j > r) {
            arr[k] = aux[i-l];
            ++i;
        }
        else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i-l];
            ++i;
        }
        else {
            arr[k] = aux[j-l];
            ++j;
        }
    }
    delete[] aux;
}

template <typename T>
void __merge_sort(T arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l+r)/2;
    __merge_sort(arr, l, mid);
    __merge_sort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template <typename T>
void merge_sort(T arr[], int n)
{
    __merge_sort(arr, 0, n - 1);
}

int main() {
    int n = 10;

    int *arr = new int[10];
    for (int i = 0; i < 10; ++i)
        scanf("%d", &arr[i]);
    merge_sort(arr, 10);

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    delete[] arr;

    return 0;
}
