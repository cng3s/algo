#include <iostream>

using namespace std;

// 二分查找法，在有序数组arr中，查找target
// 如果找到target, 返回相应index
// 没有找到target, 返回-1
template <typename T>
int binarySearch(T arr[], int n, T target) {

    // arr[l ... r]中找到target
    int l, r;
    while ( l <= r ) {

        //int mid  = (l + r) / 2;
        int mid = l + (r - l) / 2;
        if ( arr[mid] == target )
            return mid;

        if (target < arr[mid])
            r = mid - 1;
        else // target > arr[mid]
            l = mid + 1;
    }
    return -1;
}

int main() {
    return 0;
}