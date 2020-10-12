#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target){

    int l = 0, r = n - 1; // 在[l...r]的范围里寻找target
    while(l <= r){    // 当 l == r时,区间[l...r]依然是有效的
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) return mid;
        
        if(target > arr[mid])
            l = mid + 1;  // target在[mid+1...r]中; [l...mid]一定没有target
        else    // target < arr[mid]
            r = mid - 1;  // target在[l...mid-1]中; [mid...r]一定没有target
    }

    return -1;
}


// 另种写法 在 [l...r) 的范围里寻找 target

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target){

    int l = 0, r = n; // 在 [l...r) 的范围里寻找 target
    while (l < r) { // 当 l == r 时，区间 [l...r) 依然是无效的
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;

        if (target > arr[mid])
            l = mid + 1; // target在[mid+1...r)中
        else    // target < arr[mid]
            r = mid;    // target在[l...mid)中
    }

    return -1;
}

/* 注意Bug：
        int mid = (l + r) / 2;
        可能会产生整型溢出的问题
*/