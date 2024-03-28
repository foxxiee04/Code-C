#include <stdio.h>
#include <stdlib.h>

int main() {

    char *char1 = (char*)malloc(sizeof(char));
    char *char2 = (char*)malloc(sizeof(char));

    printf("Nhap ky tu thu nhat: ");
    scanf(" %c", char1);

    printf("Nhap ky tu thu hai: ");
    scanf(" %c", char2);

    printf("Cac ky tu giua %c va %c theo thu tu tang dan la:\n", *char1, *char2);

    char start = (*char1 < *char2) ? *char1 : *char2;
    char end = (*char1 < *char2) ? *char2 : *char1;

    for (char ch = start + 1; ch < end; ++ch) {
        printf("%c ", ch);
    }

    free(char1);
    free(char2);

    return 0;
}

