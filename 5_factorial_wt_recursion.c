#include <stdio.h>

int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1); 
}

int main() {
    int n, fact;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    fact = factorial(n);
    printf("Factorial of %d = %d\n", n, fact);
    
    return 0;
}
