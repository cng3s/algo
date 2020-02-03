template <typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[minIndex], arr[i]);
    }
}