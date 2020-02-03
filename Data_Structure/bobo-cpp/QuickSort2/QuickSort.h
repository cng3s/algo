//
// Created by c on 18-9-25.
//

#ifndef QUICKSORT2_QUICKSORT_H
#define QUICKSORT2_QUICKSORT_H

typedef int ElemType;

int Partition(ElemType A[], int low, int high) {
    ElemType pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(ElemType A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos-1);
        QuickSort(A, pivotpos+1, high);
    }
}

#endif //QUICKSORT2_QUICKSORT_H
