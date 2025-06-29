#include <stdio.h>

int main() {
    int n, num;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            printf("%d is EVEN\n", num);
        } else {
            printf("%d is ODD\n", num);
        }
    }
    
    return 0;
}
