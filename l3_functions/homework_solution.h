#pragma once

#include <bits/stdc++.h>

using namespace std;

template<typename T>
void quicksort(int low, int high, T &array) {
    int left = low;
    int right = high - 1;
    int middle = (low + high) / 2;
    do {
        while (array[left] < middle) left++;
        while (array[right] > middle) right--;
        if (left <= right) {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    } while (left <= right);

    if (right > low) quicksort(low, right + 1, array);
    if (left < high) quicksort(left + 1, high, array);
}

template<typename T, typename ARRAY>
int binarySearch(T x, ARRAY &array, int size) {
    int left = 0;
    int right = size;
    int middle = (left + right) / 2;
    while (array[middle] != x and left < right) {
        if (x < array[middle]) right = middle - 1;
        else if (x > array[middle]) left = middle + 1;
        middle = (left + right) / 2;
    }
    return x == array[middle] ? middle : -1;
}

uint64_t recFib(int n) {
    // 0 = 1, 1st = 1, 2nd = 2, 3rd = 3, 4th = 5, ...
    if (n < 2) return 1;
    return recFib(n - 2) + recFib(n - 1);
}

uint64_t fib_On(int n) {
    if (n < 2) return 1;
    uint64_t fib_array[n + 1];
    fib_array[0] = 1;
    fib_array[1] = 1;
    for (int i = 2; i <= n; i++) fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    return fib_array[n];
}

uint64_t fib_O1(int n) {
    n++;
    const double phi = (1 + sqrt(5)) / 2;
    return (uint64_t) round(pow(phi, n) / sqrt(5));
}

//int main() {
////    int a[10] = {9, 7, 8, 6, 4, 5, 3, 2, 0, 1};
////    vector<int> a = {9, 7, 8, 6, 4, 5, 3, 2, 0, 1};
////    quicksort(0, 10, a);
////    for (int item : a) cout << item << ' ';
////    cout << endl;
////    int pos = binarySearch(4, a, 10);
////    cout << pos << endl;
////    for (int i = 0; i < 40; i++) {
////        uint64_t fib = fib_On(i);
////        cout << fib << ' ';
////    }
////    cout << endl;
////    for (int i = 0; i < 40; i++) {
////        uint64_t fib = fib_O1(i);
////        cout << fib << ' ';
////    }
////    cout << endl;
//}