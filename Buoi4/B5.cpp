#include <stdio.h>


int timUSCLN(int a, int b) {
    if (b == 0)
        return a;
    return timUSCLN(b, a % b);
}


int timBSCNN(int a, int b) {
    return (a * b) / timUSCLN(a, b);
}

int main() {
    int so1, so2;


    printf("Nhap so thu nhat: ");
    scanf("%d", &so1);
    printf("Nhap so thu hai: ");
    scanf("%d", &so2);


    if (so1 <= 0 || so2 <= 0) {
        printf("Vui long nhap hai so nguyen duong.\n");
        return 1; 
    }


    printf("USCLN cua %d va %d la: %d\n", so1, so2, timUSCLN(so1, so2));


    printf("BSCNN cua %d va %d la: %d\n", so1, so2, timBSCNN(so1, so2));

    return 0;
}
