#include <stdio.h>


int tongChuSo(int n) {

    if (n < 10) {
        return n;
    }

    return n % 10 + tongChuSo(n / 10);
}

int main() {
    int n;
    printf("Nhập số nguyên n: ");
    scanf("%d", &n);


    printf("Tổng các chữ số của %d là: %d\n", n, tongChuSo(n));

    return 0;
}
