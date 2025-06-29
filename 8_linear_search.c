#include <stdio.h>

int search(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int array[100], n, x, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &x);
    
    result = search(array, n, x);
    
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n", result);
    
    return 0;
}
