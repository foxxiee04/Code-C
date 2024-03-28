#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// H�m nh?p m?ng s? th?c
void nhapMang(float **arr, int n) {
    *arr = (float*)malloc(n * sizeof(float));

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; ++i) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%f", (*arr) + i);
    }
}

// H�m xu?t m?ng
void xuatMang(float *arr, int n) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// H�m t�nh gi� tr? trung b�nh c?a m?ng
float tinhTrungBinh(float *arr, int n) {
    float tong = 0.0;
    for (int i = 0; i < n; ++i) {
        tong += arr[i];
    }
    return tong / n;
}

// H�m t�nh t?ng b�nh phuong c?a m?ng
float tinhTongBinhPhuong(float *arr, int n) {
    float tongBinhPhuong = 0.0;
    for (int i = 0; i < n; ++i) {
        tongBinhPhuong += arr[i] * arr[i];
    }
    return tongBinhPhuong;
}

// H�m t�nh phuong sai c?a m?ng
float tinhPhuongSai(float *arr, int n, float trungBinh) {
    float phuongSai = 0.0;
    for (int i = 0; i < n; ++i) {
        phuongSai += (arr[i] - trungBinh) * (arr[i] - trungBinh);
    }
    return phuongSai / n;
}

// H�m t�nh d? l?ch chu?n c?a m?ng
float tinhDoLechChuan(float phuongSai) {
    return sqrt(phuongSai);
}

// H�m th�m gi� tr? X v�o v? tr� P
void themGiaTri(float **arr, int *n, float X, int P) {
    *n += 1;
    *arr = (float*)realloc(*arr, *n * sizeof(float));

    for (int i = *n - 1; i > P; --i) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[P] = X;
}

// H�m x�a ph?n t? t?i v? tr� P
void xoaPhanTu(float *arr, int *n, int P) {
    for (int i = P; i < *n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    *n -= 1;
}

// H�m t�m ki?m gi� tr? X trong m?ng
int timKiem(float *arr, int n, float X) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == X) {
            return i;
        }
    }
    return -1;
}

// H�m s?p x?p m?ng tang d?n
void sapXepTangDan(float *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// H�m s?p x?p m?ng gi?m d?n
void sapXepGiamDan(float *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    float *mang;

    // Nh?p s? ph?n t? c?a m?ng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    // Nh?p m?ng s? th?c
    nhapMang(&mang, n);

    // Xu?t m?ng
    xuatMang(mang, n);

    // T�nh gi� tr? trung b�nh c?a m?ng
    float trungBinh = tinhTrungBinh(mang, n);
    printf("Gia tri trung binh cua mang: %.2f\n", trungBinh);

    // T�nh t?ng b�nh phuong c?a m?ng
    float tongBinhPhuong = tinhTongBinhPhuong(mang, n);
    printf("Tong binh phuong cua mang: %.2f\n", tongBinhPhuong);

    // T�nh phuong sai c?a m?ng
    float phuongSai = tinhPhuongSai(mang, n, trungBinh);
    printf("Phuong sai cua mang: %.2f\n", phuongSai);

    // T�nh d? l?ch chu?n c?a m?ng
    float doLechChuan = tinhDoLechChuan(phuongSai);
    printf("Do lech chuan cua mang: %.2f\n", doLechChuan);

    // Th�m gi� tr? X v�o v? tr� P
    float X;
    int P;
    printf("Nhap gia tri X can them: ");
    scanf("%f", &X);
    printf("Nhap vi tri P: ");
    scanf("%d", &P);
    themGiaTri(&mang, &n, X, P);

    // Xu?t m?ng sau khi th�m gi� tr?
    xuatMang(mang, n);

    // X�a ph?n t? t?i v? tr� P
    printf("Nhap vi tri P can xoa: ");
    scanf("%d", &P);
    xoaPhanTu(mang, &n, P);

    // Xu?t m?ng sau khi x�a gi� tr?
    xuatMang(mang, n);

    // T�m ki?m gi� tr? X trong m?ng
    printf("Nhap gia tri X can tim kiem: ");
    scanf("%f", &X);
    int viTriTimKiem = timKiem(mang, n, X);
    if (viTriTimKiem != -1) {
        printf("Gia tri %.2f duoc tim thay tai vi tri %d.\n", X, viTriTimKiem);
    } else {
        printf("Gia tri %.2f khong tim thay trong mang.\n", X);
    }

    // S?p x?p m?ng tang d?n v� xu?t m?ng sau khi s?p x?p
    sapXepTangDan(mang, n);
    printf("Mang sau khi sap xep tang dan:\n");
    xuatMang(mang, n);

    // S?p x?p m?ng gi?m d?n v� xu?t m?ng sau khi s?p x?p
    sapXepGiamDan(mang, n);
    printf("Mang sau khi sap xep giam dan:\n");
    xuatMang(mang, n);

    // Gi?i ph�ng b? nh? d� c?p ph�t d?ng
    free(mang);

    return 0;
}

