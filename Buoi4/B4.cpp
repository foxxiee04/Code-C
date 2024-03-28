#include <stdio.h>


int fibonacci(int n) {

    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);


    printf("Dãy Fibonacci cho đến số thứ %d là:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
