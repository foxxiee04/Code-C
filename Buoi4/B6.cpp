#include <stdio.h>
int count;
int A(int m, int n) {
	count++;
    if (m == 0) 
        return n + 1;
    else if (n == 0) 
        return A(m - 1, 1);
    else 
        return A(m - 1, A(m, n - 1));
}

int main() {
    int m, n;
    printf("Nhap gia tri m: ");
    scanf("%d", &m);
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    int kq = A(m, n);
    printf("\nKet qua A(%d, %d): %d", m, n, kq);
	printf("\nSo lan goi de quy la: %d", count);

    return 0;
}
