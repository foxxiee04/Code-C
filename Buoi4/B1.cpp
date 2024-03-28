#include <stdio.h>

void Nhap(int a[], int n) {
    if(n == 0)
        return;
    Nhap(a, n - 1);
    printf("Nhap phan tu thu %d: ", n);
    scanf("%d", &a[n - 1]);
}

void Xuat(int a[], int n) {
    if(n == 0)
        return;
    Xuat(a, n - 1);
    printf("%d\t", a[n - 1]);
}

int Tong(int a[], int n) {
    if (n == 0)
        return 0;
    return a[n - 1] + Tong(a, n - 1);
}

int TongChan(int a[], int n) {
    if (n == 0)
        return 0;
    if (a[n - 1] % 2 == 0)
        return a[n - 1] + TongChan(a, n - 1);
    else
        return TongChan(a, n - 1);
}

int DemDuong(int a[], int n) {
    if (n == 0)
        return 0;
    if (a[n - 1] > 0)
        return 1 + DemDuong(a, n - 1);
    else
        return DemDuong(a, n - 1);
}

int TimMax(int a[], int n) {
    if (n == 1)
        return a[0];
    int max = TimMax(a, n - 1);
    return (a[n - 1] > max) ? a[n - 1] : max;
}

int TimMin(int a[], int n) {
    if (n == 1)
        return a[0];
    int min = TimMin(a, n - 1);
    return (a[n - 1] < min) ? a[n - 1] : min;
}

int TimChanCuoi(int a[], int n) {
    if (n == 0)
        return -1;
    if (a[n - 1] % 2 == 0)
        return n - 1;
    else
        return TimChanCuoi(a, n - 1);
}

int TimViTriCuoi(int a[], int n, int x) {
    if (n == 0)
        return -1;
    if (a[n - 1] == x)
        return n - 1;
    else
        return TimViTriCuoi(a, n - 1, x);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    Nhap(a, n);

    int choice;
    do {
        printf("\nChon cac yeu cau: \n");
        printf("1. Xuat mang\n");
        printf("2. Tinh tong cac phan tu cua mang\n");
        printf("3. Tinh tong cac phan tu chan cua mang\n");
        printf("4. Dem so luong phan tu duong cua mang\n");
        printf("5. Tim phan tu lon nhat cua mang\n");
        printf("6. Tim phan tu nho nhat cua mang\n");
        printf("7. Tim phan tu chan cuoi cung trong mang\n");
        printf("8. Tim vi tri cuoi cung cua mot gia tri x trong mang\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Mang: ");
                Xuat(a, n);
                break;
            case 2:
                printf("Tong cac phan tu cua mang la: %d\n", Tong(a, n));
                break;
            case 3:
                printf("Tong cac phan tu chan cua mang la: %d\n", TongChan(a, n));
                break;
            case 4:
                printf("So luong phan tu duong cua mang la: %d\n", DemDuong(a, n));
                break;
            case 5:
                printf("Phan tu lon nhat cua mang la: %d\n", TimMax(a, n));
                break;
            case 6:
                printf("Phan tu nho nhat cua mang la: %d\n", TimMin(a, n));
                break;
            case 7:
                if (TimChanCuoi(a, n) != -1)
                    printf("Phan tu chan cuoi cung trong mang la: %d\n", a[TimChanCuoi(a, n)]);
                else
                    printf("Khong co phan tu chan trong mang.\n");
                break;
            case 8:
                int x;
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                if (TimViTriCuoi(a, n, x) != -1)
                    printf("Vi tri cuoi cung cua gia tri %d trong mang la: %d\n", x, TimViTriCuoi(a, n, x));
                else
                    printf("Khong tim thay gia tri %d trong mang.\n", x);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}
