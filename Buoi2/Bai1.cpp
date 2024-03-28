#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];


    printf("Nhap chuoi s1: ");
    scanf("%s", s1);
    printf("Nhap chuoi s2: ");
    scanf("%s", s2);


    printf("Chuoi vua nhap:\n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);


    printf("Do dai cua chuoi s1: %d\n", strlen(s1));
    printf("Do dai cua chuoi s2: %d\n", strlen(s2));


    int compare_result = strcmp(s1, s2);
    if (compare_result == 0)
        printf("s1 va s2 giong nhau.\n");
    else if (compare_result < 0)
        printf("s1 nho hon s2.\n");
    else
        printf("s1 lon hon s2.\n");


    strcat(s1, s2);
    printf("Chuoi sau khi noi s2 vao s1: %s\n", s1);


    if (strstr(s1, s2) != NULL)
        printf("s1 chua chuoi s2.\n");
    else
        printf("s1 khong chua chuoi s2.\n");


    if (strstr(s2, s1) != NULL)
        printf("s2 chua chuoi s1.\n");
    else
        printf("s2 khong chua chuoi s1.\n");

    return 0;
}

