#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == key) return m;
        if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int key = 7;
    int res = binarySearch(arr, 5, key);

    res == -1 ? printf("Not found\n") : printf("Found at index %d\n", res);
    return 0;
}
