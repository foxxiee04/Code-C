#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Ngay {
    unsigned char ngay;
    unsigned char thang;
    int nam;
};


struct BuuKien {
    char maBuuKien[11];
    char tenNguoiGui[50];
    char tenNguoiNhan[50];
    float trongLuong;
    struct Ngay ngayGui;
    char noiDung[100];
    float donGiaGui;
};


void NhapThongTinBuuKien(struct BuuKien *bk);
void XuatThongTinBuuKien(struct BuuKien bk);
void NhapDanhSachBuuKien(struct BuuKien dsBuuKien[], int *n);
void XuatDanhSachBuuKien(struct BuuKien dsBuuKien[], int n);
void ThemBuuKien(struct BuuKien dsBuuKien[], int *n);
void SapXepTheoMaBuuKien(struct BuuKien dsBuuKien[], int n);
float TinhGiaTriBuuKien(struct BuuKien bk);
int DemBuuKienTrongLuongLonNhat(struct BuuKien dsBuuKien[], int n);

int main() {
    struct BuuKien dsBuuKien[100]; 
    int n = 0; 

    int choice;
    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap thong tin buu kien\n");
        printf("2. Xuat thong tin buu kien\n");
        printf("3. Them mot buu kien\n");
        printf("4. Sap xep danh sach buu kien theo ma buu kien\n");
        printf("5. Tinh gia tri cua moi buu kien\n");
        printf("6. Dem so luong buu kien co trong luong lon nhat\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                NhapDanhSachBuuKien(dsBuuKien, &n);
                break;
            case 2:
                XuatDanhSachBuuKien(dsBuuKien, n);
                break;
            case 3:
                ThemBuuKien(dsBuuKien, &n);
                break;
            case 4:
                SapXepTheoMaBuuKien(dsBuuKien, n);
                break;
            case 5:
                printf("\nGia tri cua tung buu kien:\n");
                for (int i = 0; i < n; i++) {
                    printf("Buu kien %d: %.2f\n", i + 1, TinhGiaTriBuuKien(dsBuuKien[i]));
                }
                break;
            case 6:
                printf("\nSo luong buu kien co trong luong lon nhat: %d\n", DemBuuKienTrongLuongLonNhat(dsBuuKien, n));
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


void NhapThongTinBuuKien(struct BuuKien *bk) {
    printf("Nhap ma buu kien: ");
    scanf("%s", bk->maBuuKien);
    printf("Nhap ten nguoi gui: ");
    scanf("%s", bk->tenNguoiGui);
    printf("Nhap ten nguoi nhan: ");
    scanf("%s", bk->tenNguoiNhan);
    printf("Nhap trong luong (kg): ");
    scanf("%f", &bk->trongLuong);
    printf("Nhap ngay gui (ngay thang nam): ");
    scanf("%hhu %hhu %d", &bk->ngayGui.ngay, &bk->ngayGui.thang, &bk->ngayGui.nam);
    printf("Nhap noi dung buu kien: ");
    scanf("%s", bk->noiDung);
    printf("Nhap don gia gui: ");
    scanf("%f", &bk->donGiaGui);
}


void XuatThongTinBuuKien(struct BuuKien bk) {
    printf("\nMa buu kien: %s\n", bk.maBuuKien);
    printf("Ten nguoi gui: %s\n", bk.tenNguoiGui);
    printf("Ten nguoi nhan: %s\n", bk.tenNguoiNhan);
    printf("Trong luong: %.2f kg\n", bk.trongLuong);
    printf("Ngay gui: %02hhu/%02hhu/%4d\n", bk.ngayGui.ngay, bk.ngayGui.thang, bk.ngayGui.nam);
    printf("Noi dung buu kien: %s\n", bk.noiDung);
    printf("Don gia gui: %.2f\n", bk.donGiaGui);
}


void NhapDanhSachBuuKien(struct BuuKien dsBuuKien[], int *n) {
    printf("Nhap so luong buu kien: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin cho buu kien %d:\n", i + 1);
        NhapThongTinBuuKien(&dsBuuKien[i]);
    }
}


void XuatDanhSachBuuKien(struct BuuKien dsBuuKien[], int n) {
    printf("\n========== DANH SACH BUU KIEN ==========\n");
    for (int i = 0; i < n; i++) {
        printf("\nThong tin buu kien %d:\n", i + 1);
        XuatThongTinBuuKien(dsBuuKien[i]);
    }
}


void ThemBuuKien(struct BuuKien dsBuuKien[], int *n) {
    if (*n < 100) {
        printf("\nNhap thong tin cho buu kien moi:\n");
        NhapThongTinBuuKien(&dsBuuKien[*n]);
        (*n)++;
    } else {
        printf("\nDanh sach buu kien da day, khong the them moi.\n");
    }
}


void SapXepTheoMaBuuKien(struct BuuKien dsBuuKien[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(dsBuuKien[i].maBuuKien, dsBuuKien[j].maBuuKien) > 0) {
                struct BuuKien temp = dsBuuKien[i];
                dsBuuKien[i] = dsBuuKien[j];
                dsBuuKien[j] = temp;
            }
        }
    }
}


float TinhGiaTriBuuKien(struct BuuKien bk) {
    return bk.trongLuong * bk.donGiaGui;
}


int DemBuuKienTrongLuongLonNhat(struct BuuKien dsBuuKien[], int n) {
    float maxTrongLuong = dsBuuKien[0].trongLuong;
    for (int i = 1; i < n; i++) {
        if (dsBuuKien[i].trongLuong > maxTrongLuong) {
            maxTrongLuong = dsBuuKien[i].trongLuong;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (dsBuuKien[i].trongLuong == maxTrongLuong) {
            count++;
        }
    }
    return count;
}
