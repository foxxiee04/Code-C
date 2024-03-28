#include <stdio.h>
#include <stdlib.h>

int main() {

    float *num1 = (float*)malloc(sizeof(float));
    float *num2 = (float*)malloc(sizeof(float));


    printf("Nhap so thu nhat: ");
    scanf("%f", num1);

    printf("Nhap so thu hai: ");
    scanf("%f", num2);


    float sum = *num1 + *num2;
    float difference = *num1 - *num2;
    float product = *num1 * *num2;


    if (*num2 != 0) {
        float quotient = *num1 / *num2;
        printf("Tong: %.2f\n", sum);
        printf("Hieu: %.2f\n", difference);
        printf("Tich: %.2f\n", product);
        printf("Thuong: %.2f\n", quotient);
    } else {
        printf("Khong the chia cho 0.\n");
    }


    free(num1);
    free(num2);

    return 0;
}

