#include <stdio.h>
#include <string.h>


void left(const char *str, int n) {
    printf("So ki tu ben trai: ", n);
    for (int i = 0; i < n && str[i] != '\0'; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}


void right(const char *str, int n) {
    int len = strlen(str);
    printf("So ki tu ben phai: ", n);
    for (int i = len - n; i < len; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    int n;

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);


    input[strcspn(input, "\n")] = '\0';

    printf("So ki tu can trich xuat: ");
    scanf("%d", &n);

    left(input, n);
    right(input, n);

    return 0;
}

