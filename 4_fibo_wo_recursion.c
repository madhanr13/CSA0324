#include <stdio.h>

int main() {
    int n = 10; // Number of terms
    int t1 = 0, t2 = 1;

    printf("Fibonacci Series: %d, %d", t1, t2);

    for (int i = 3; i <= n; i++) {
        int next = t1 + t2;
        printf(", %d", next);
        t1 = t2;
        t2 = next;
    }

    printf("\n");
    return 0;
}
// Output:
// Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55