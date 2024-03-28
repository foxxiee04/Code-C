#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100

struct Book {
    char maSach[11];
    char tenSach[50];
    char tenTacGia[50];
    char loaiSach[10];
    int namXuatBan;
    float giaTien;
    int soLuong;
};

void nhapThongTinSach(struct Book *sach) {
    printf("Nhap ma sach: ");
    scanf("%s", sach->maSach);
    printf("Nhap ten sach: ");
    scanf("%s", sach->tenSach);
    printf("Nhap ten tac gia: ");
    scanf("%s", sach->tenTacGia);
    printf("Nhap loai sach (Tu nhien(1) / Xa hoi(2)): ");
    scanf("%s", sach->loaiSach);
    printf("Nhap nam xuat ban: ");
    scanf("%d", &sach->namXuatBan);
    printf("Nhap gia tien: ");
    scanf("%f", &sach->giaTien);
    printf("Nhap so luong: ");
    scanf("%d", &sach->soLuong);
}

void xuatThongTinSach(struct Book sach) {
    printf("Ma sach: %s\n", sach.maSach);
    printf("Ten sach: %s\n", sach.tenSach);
    printf("Ten tac gia: %s\n", sach.tenTacGia);
    printf("Loai sach: %s\n", sach.loaiSach);
    printf("Nam xuat ban: %d\n", sach.namXuatBan);
    printf("Gia tien: %.2f\n", sach.giaTien);
    printf("So luong: %d\n", sach.soLuong);
}

void themSach(struct Book danhSachSach[], int *soLuongSach) {
    if (*soLuongSach < MAX_BOOKS) {
        printf("Nhap thong tin cho sach moi:\n");
        nhapThongTinSach(&danhSachSach[*soLuongSach]);
        (*soLuongSach)++;
    } else {
        printf("Danh sach da day, khong the them sach moi.\n");
    }
}

float tinhTongThanhTien(struct Book danhSachSach[], int soLuongSach) {
    float tongThanhTien = 0;
    for (int i = 0; i < soLuongSach; i++) {
        tongThanhTien += danhSachSach[i].giaTien * danhSachSach[i].soLuong;
    }
    return tongThanhTien;
}

void sapXepTheoMaSach(struct Book danhSachSach[], int soLuongSach) {
    struct Book temp;
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if (strcmp(danhSachSach[i].maSach, danhSachSach[j].maSach) > 0) {
                temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
}

void timTheoTenSach(struct Book danhSachSach[], int soLuongSach, char tenSachCanTim[]) {
    bool found = false;
    printf("Cac sach co ten sach chua '%s':\n", tenSachCanTim);
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(danhSachSach[i].tenSach, tenSachCanTim) != NULL) {
            xuatThongTinSach(danhSachSach[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Khong tim thay sach nao co ten chua '%s'.\n", tenSachCanTim);
    }
}

void xuatTheoXuatBanTruocNam(struct Book danhSachSach[], int soLuongSach, int nam) {
    printf("Cac sach xuat ban truoc nam %d:\n", nam);
    for (int i = 0; i < soLuongSach; i++) {
        if (danhSachSach[i].namXuatBan < nam) {
            xuatThongTinSach(danhSachSach[i]);
        }
    }
}

int demSachGiaLonHon(struct Book danhSachSach[], int soLuongSach, float gia) {
    int count = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (danhSachSach[i].giaTien > gia) {
            count++;
        }
    }
    return count;
}

void xuatTheoLoai(struct Book danhSachSach[], int soLuongSach, char loaiCanTim[]) {
    printf("Cac sach thuoc loai '%s':\n", loaiCanTim);
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].loaiSach, loaiCanTim) == 0) {
            xuatThongTinSach(danhSachSach[i]);
        }
    }
}

int main() {
    struct Book danhSachSach[MAX_BOOKS];
    int soLuongSach = 0;
    int luaChon;
    char tenSachCanTim[50];
    int nam;
    float gia;
    char loaiCanTim[10];

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap thong tin cac cuon sach\n");
        printf("2. Xuat thong tin cac cuon sach\n");
        printf("3. Them mot cuon sach vao danh sach\n");
        printf("4. Tinh tong thanh tien cua tat ca cac cuon sach\n");
        printf("5. Sap xep danh sach sach theo ma sach\n");
        printf("6. Tim sach theo ten sach\n");
        printf("7. Xuat sach xuat ban truoc nam\n");
        printf("8. Dem so luong sach co gia lon hon\n");
        printf("9. Xuat sach theo loai\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap thong tin cac cuon sach:\n");
                themSach(danhSachSach, &soLuongSach);
                break;
            case 2:
                printf("Xuat thong tin cac cuon sach:\n");
                for (int i = 0; i < soLuongSach; i++) {
                    xuatThongTinSach(danhSachSach[i]);
                }
                break;
            case 3:
                printf("Them mot cuon sach moi:\n");
                themSach(danhSachSach, &soLuongSach);
                break;
            case 4:
                printf("Tong thanh tien cua tat ca cac cuon sach: %.2f\n", tinhTongThanhTien(danhSachSach, soLuongSach));
                break;
            case 5:
                printf("Sap xep danh sach sach theo ma sach:\n");
                sapXepTheoMaSach(danhSachSach, soLuongSach);
                break;
            case 6:
                printf("Nhap ten sach can tim: ");
                scanf("%s", tenSachCanTim);
                timTheoTenSach(danhSachSach, soLuongSach, tenSachCanTim);
                break;
            case 7:
                printf("Nhap nam: ");
                scanf("%d", &nam);
                xuatTheoXuatBanTruocNam(danhSachSach, soLuongSach, nam);
                break;
            case 8:
                printf("Nhap gia: ");
                scanf("%f", &gia);
                printf("So luong sach co gia lon hon %.2f: %d\n", gia, demSachGiaLonHon(danhSachSach, soLuongSach, gia));
                break;
            case 9:
                printf("Nhap loai sach can xuat (Tu nhien / Xa hoi): ");
                scanf("%s", loaiCanTim);
                xuatTheoLoai(danhSachSach, soLuongSach, loaiCanTim);
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}
