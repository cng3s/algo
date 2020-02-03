#include <iostream>
#include "QuickSort.h"

int main() {
    int A[9] = {0,9,2,6,5 };
    QuickSort(A, 1, 8);
    for (int i : A)
        std::cout << i << " ";

    return 0;
}