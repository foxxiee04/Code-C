#include <stdio.h>
#include <ctype.h>
#include <string.h>


void xoaKhoangTrangThua(char *str) {
    int i, j;
    int len = strlen(str);


    while (isspace(str[0])) {
        memmove(str, str + 1, len--);
    }


    while (isspace(str[len - 1])) {
        len--;
    }
    str[len] = '\0';


    for (i = 0, j = 0; str[i]; i++) {
        if (isspace(str[i]) && isspace(str[i + 1])) {
            continue;
        }
        str[j++] = str[i];
    }
    str[j] = '\0';
}


void inHoaDauTu(char *str) {
    int i;

    str[0] = toupper(str[0]);


    for (i = 1; str[i] != '\0'; i++) {

        if (isspace(str[i - 1])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);


    xoaKhoangTrangThua(str);
    inHoaDauTu(str);


    printf("Chuoi sau khi xu li: %s\n", str);

    return 0;
}

