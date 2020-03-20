#include <iostream>
#include "QuickSort_1.h"
#include "QuickSort_2.h"
#include "MergeSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"
#include "QuickSort3Ways2.h"
#include "SortTestHelper.h"
using namespace std;

int main() {

    int n = 0x3fffffff;
    //int n = 30;
    // 测试1 一般性测试

    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("QuickSort3Ways1: ", QuickSort3Ways, arr2, n);
    SortTestHelper::testSort("QuickSort3Ways2", QuickSort3Ways2, arr1, n);
    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    // 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
    // 但是对于近乎有序的数组, 其效率比优化后的归并排序要低, 但完全再容忍范围里
    // 思考一下为什么对于近乎有序的数组, 快排的性能比优化后的归并排序低? :)
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("QuickSort3Ways1: ", QuickSort3Ways, arr2, n);
    SortTestHelper::testSort("QuickSort3Ways2", QuickSort3Ways2, arr1, n);
    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    // 但此时, 对于含有大量相同元素的数组, 我们的快速排序算法再次退化成了O(n^2)级别的算法
    // 思考一下为什么在这种情况下, 快排退化成了O(n^2)的算法? :)
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("QuickSort3Ways1: ", QuickSort3Ways, arr2, n);
    SortTestHelper::testSort("QuickSort3Ways2", QuickSort3Ways2, arr1, n);
    delete[] arr1;
    delete[] arr2;

    return 0;
}
