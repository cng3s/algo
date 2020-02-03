template <typename T>
void shellInsertionSort(T arr[], int n, int start, int gap) {
    // Shell排序的内部函数
    for (int i = start + gap; i < n; i += gap) {
        T e = arr[i];
        int j;
        for (j = i; j - gap >= 0 && arr[j - gap] > e; j -= gap)
            arr[j] = arr[j - gap];
        arr[j] = e;
    }
}

template <typename T>
void shellSort(T arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = 0; i < gap; i ++)
            shellInsertionSort(arr, n, i, gap);
}