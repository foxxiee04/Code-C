#include <stdio.h>


void chuyenDia(int n, char cocNguon, char cocDich, char cocPhu) {
    if (n == 1) {
        printf("Chuyen dia tu coc %c sang coc %c\n", cocNguon, cocDich);
        return;
    }


    chuyenDia(n - 1, cocNguon, cocPhu, cocDich);
    

    printf("Chuyen dia tu coc %c sang coc %c\n", cocNguon, cocDich);
    

    chuyenDia(n - 1, cocPhu, cocDich, cocNguon);
}

int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);

    chuyenDia(n, 'A', 'C', 'B');
    return 0;
}
