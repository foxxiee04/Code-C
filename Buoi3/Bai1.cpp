#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100


struct DATE {
    unsigned char ngay;
    unsigned char thang;
    int nam;
};


typedef struct SinhVien {
    char ma[11];
    char hoten[31];
    struct DATE ns; 
    char gt; 
    char lop[8];
    float dtb; 
} SV;


void NhapNgaySinh(struct DATE &d);
void XuatNgaySinh(struct DATE d);
void Nhap1sv(SV &x);
void Xuat1sv(SV x);
void Nhapsl(int &n);
void Nhapds(SV a[], int n);
void Xuatds(SV a[], int n);
void XuatDSTBGT5(SV a[], int n);
void XuatDSNganhCNTT(SV a[], int n);
int DemSinhVienNu(SV a[], int n);
void XuatSVDiemCaoNhat(SV a[], int n);
void ThemSinhVien(SV a[], int &n);
void TimVaXoaSinhVien(SV a[], int &n, char maTim[]);
void SapXepTheoDiemTB(SV a[], int n);

int main() {
    SV a[MAX];
    int n;
    int choice;
    char maTim[11];

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Xuat sinh vien co diem trung binh > 5\n");
        printf("4. Xuat sinh vien thuoc nganh Cong Nghe Thong Tin\n");
        printf("5. Dem so luong sinh vien nu\n");
        printf("6. Xuat sinh vien co diem trung binh cao nhat\n");
        printf("7. Them sinh vien moi\n");
        printf("8. Tim va xoa sinh vien theo ma\n");
        printf("9. Sap xep danh sach sinh vien theo diem trung binh\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Nhapsl(n);
                Nhapds(a, n);
                break;
            case 2:
                Xuatds(a, n);
                break;
            case 3:
                printf("\nSinh vien co diem trung binh > 5:\n");
                XuatDSTBGT5(a, n);
                break;
            case 4:
                printf("\nSinh vien thuoc nganh Cong Nghe Thong Tin:\n");
                XuatDSNganhCNTT(a, n);
                break;
            case 5:
                printf("\nSo luong sinh vien nu: %d\n", DemSinhVienNu(a, n));
                break;
            case 6:
                printf("\nSinh vien co diem trung binh cao nhat:\n");
                XuatSVDiemCaoNhat(a, n);
                break;
            case 7:
                printf("\nThem mot sinh vien moi:\n");
                ThemSinhVien(a, n);
                break;
            case 8:
                printf("\nNhap ma sinh vien can tim va xoa: ");
                scanf("%s", maTim);
                TimVaXoaSinhVien(a, n, maTim);
                break;
            case 9:
                printf("\nDanh sach sau khi sap xep theo diem trung binh tang dan:\n");
                SapXepTheoDiemTB(a, n);
                Xuatds(a, n);
                break;
            case 0:
                printf("\nKet thuc chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}



void NhapNgaySinh(struct DATE &d) {
    printf("Nhap vao ngay: ");
    scanf("%u", &d.ngay);
    printf("Nhap vao thang: ");
    scanf("%u", &d.thang);
    printf("Nhap vao nam: ");
    scanf("%d", &d.nam);
}


void XuatNgaySinh(struct DATE d) {
    printf("%02u / %02u / %4d", d.ngay, d.thang, d.nam);
}


void Nhap1sv(SV &x) {
    printf("Nhap ma sinh vien: ");
    scanf("%s", &x.ma);
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(x.hoten);
    printf("Nhap ngay thang nam sinh: ");
    NhapNgaySinh(x.ns);
    printf("Nhap lop: ");
    scanf("%s", &x.lop);
    do {
        printf("Nhap gioi tinh x-nu, y-nam: ");
        x.gt = getche();
    } while (x.gt != 'x' && x.gt != 'y');
    printf("\nNhap vao diem trung binh: ");
    scanf("%f", &x.dtb);
}


void Xuat1sv(SV x) {
    printf("\n%-11s%-30s", x.ma, x.hoten);
    if (x.gt == 'x')
        printf("nu\t");
    else
        printf("nam\t");
    XuatNgaySinh(x.ns);
    printf("\t%-8s%.1f\n", x.lop, x.dtb);
}


void Nhapsl(int &n) {
    do {
        printf("Nhap so luong sinh vien (>0): ");
        scanf("%d", &n);
    } while (n <= 0);
}


void Nhapds(SV a[], int n) {
	printf("NHAP DANH SACH SINH VIEN-----------\n");
    for (int i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);
        Nhap1sv(a[i]);
    }
}


void Xuatds(SV a[], int n) {
    printf("\nDANH SACH SINH VIEN----------------\n");
    for (int i = 0; i < n; i++)
        Xuat1sv(a[i]);
}


void XuatDSTBGT5(SV a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].dtb > 5.0)
            Xuat1sv(a[i]);
    }
}


void XuatDSNganhCNTT(SV a[], int n) {
    for (int i = 0; i < n; i++) {
        if (strncmp(a[i].lop + 2, "CNTT", 4) == 0)
            Xuat1sv(a[i]);
    }
}


int DemSinhVienNu(SV a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].gt == 'x')
            dem++;
    }
    return dem;
}


void XuatSVDiemCaoNhat(SV a[], int n) {
    float maxDTB = a[0].dtb;
    for (int i = 1; i < n; i++) {
        if (a[i].dtb > maxDTB)
            maxDTB = a[i].dtb;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].dtb == maxDTB)
            Xuat1sv(a[i]);
    }
}


void ThemSinhVien(SV a[], int &n) {
    if (n < MAX) {
        printf("\nNhap thong tin cho sinh vien moi:\n");
        Nhap1sv(a[n]);
        n++;
    } else {
        printf("\nDanh sach day, khong the them sinh vien moi.\n");
    }
}


void TimVaXoaSinhVien(SV a[], int &n, char maTim[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(a[i].ma, maTim) == 0)
            break;
    }
    if (i < n) {
        for (int j = i; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        n--;
        printf("\nDa xoa sinh vien co ma %s.\n", maTim);
    } else {
        printf("\nKhong tim thay sinh vien co ma %s.\n", maTim);
    }
}


void SapXepTheoDiemTB(SV a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].dtb > a[j].dtb) {
                SV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
