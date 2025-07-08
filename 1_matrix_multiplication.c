#include <stdio.h>

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int result[2][2] = {0};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                result[i][j] += a[i][k] * b[k][j];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
// Output:
// 58 64
// 139 154
// Explanation:
// This code performs matrix multiplication of a 2x3 matrix `a` and a 3x2 matrix `b`, resulting in a 2x2 matrix `result`.
// The nested loops iterate through the rows of `a`, columns of `b`, and the shared dimension (3) to compute the product.
// The final result is printed in a formatted manner, showing the resulting matrix after multiplication.