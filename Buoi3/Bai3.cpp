#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct ThueBao {
    char maThueBao[11];
    char hoTen[50];
    struct Ngay ngayDangKy;
    char soDienThoai[12];
    char loaiThueBao[3];
    int thoiGianNoiMang;
    int thoiGianNgoaiMang;
};

void nhapThongTinThueBao(struct ThueBao *thueBao) {
    printf("Nhap ma thue bao: ");
    scanf("%s", thueBao->maThueBao);
    printf("Nhap ho ten chu thue bao: ");
    scanf("%s", thueBao->hoTen);
    printf("Nhap ngay dang ky (ngay thang nam): ");
    scanf("%d %d %d", &thueBao->ngayDangKy.ngay, &thueBao->ngayDangKy.thang, &thueBao->ngayDangKy.nam);
    printf("Nhap so dien thoai: ");
    scanf("%s", thueBao->soDienThoai);
    printf("Nhap loai thue bao (TT/TS): ");
    scanf("%s", thueBao->loaiThueBao);
    printf("Nhap thoi gian goi noi mang (phut): ");
    scanf("%d", &thueBao->thoiGianNoiMang);
    printf("Nhap thoi gian goi ngoai mang (phut): ");
    scanf("%d", &thueBao->thoiGianNgoaiMang);
}

void xuatThongTinThueBao(struct ThueBao thueBao) {
    printf("Ma thue bao: %s\n", thueBao.maThueBao);
    printf("Ho ten chu thue bao: %s\n", thueBao.hoTen);
    printf("Ngay dang ky: %d/%d/%d\n", thueBao.ngayDangKy.ngay, thueBao.ngayDangKy.thang, thueBao.ngayDangKy.nam);
    printf("So dien thoai: %s\n", thueBao.soDienThoai);
    printf("Loai thue bao: %s\n", thueBao.loaiThueBao);
    printf("Thoi gian goi noi mang: %d phut\n", thueBao.thoiGianNoiMang);
    printf("Thoi gian goi ngoai mang: %d phut\n", thueBao.thoiGianNgoaiMang);
}

void themThueBao(struct ThueBao danhSachThueBao[], int *soLuongThueBao) {
    if (*soLuongThueBao < MAX_SUBSCRIBERS) {
        printf("Nhap thong tin cho thue bao moi:\n");
        nhapThongTinThueBao(&danhSachThueBao[*soLuongThueBao]);
        (*soLuongThueBao)++;
    } else {
        printf("Danh sach da day, khong the them thue bao moi.\n");
    }
}

void sapXepTheoMaThueBao(struct ThueBao danhSachThueBao[], int soLuongThueBao) {
    struct ThueBao temp;
    for (int i = 0; i < soLuongThueBao - 1; i++) {
        for (int j = i + 1; j < soLuongThueBao; j++) {
            if (strcmp(danhSachThueBao[i].maThueBao, danhSachThueBao[j].maThueBao) > 0) {
                temp = danhSachThueBao[i];
                danhSachThueBao[i] = danhSachThueBao[j];
                danhSachThueBao[j] = temp;
            }
        }
    }
}

void timTheoHoTen(struct ThueBao danhSachThueBao[], int soLuongThueBao, char hoTenCanTim[]) {
    bool found = false;
    printf("Cac thue bao co chu theo ten '%s':\n", hoTenCanTim);
    for (int i = 0; i < soLuongThueBao; i++) {
        if (strstr(danhSachThueBao[i].hoTen, hoTenCanTim) != NULL) {
            xuatThongTinThueBao(danhSachThueBao[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Khong tim thay thue bao nao theo ten '%s'.\n", hoTenCanTim);
    }
}

void xuatTheoLoai(struct ThueBao danhSachThueBao[], int soLuongThueBao, char loaiCanTim[]) {
    printf("Cac thue bao thuoc loai '%s':\n", loaiCanTim);
    for (int i = 0; i < soLuongThueBao; i++) {
        if (strcmp(danhSachThueBao[i].loaiThueBao, loaiCanTim) == 0) {
            xuatThongTinThueBao(danhSachThueBao[i]);
        }
    }
}

void xuatTheoDangKySauNam(struct ThueBao danhSachThueBao[], int soLuongThueBao, int nam) {
    printf("Cac thue bao dang ky sau nam %d:\n", nam);
    for (int i = 0; i < soLuongThueBao; i++) {
        if (danhSachThueBao[i].ngayDangKy.nam > nam) {
            xuatThongTinThueBao(danhSachThueBao[i]);
        }
    }
}

float tinhCuocPhi(struct ThueBao thueBao) {
    float cuocNoiMang = thueBao.thoiGianNoiMang * 1500.0;
    float cuocNgoaiMang = thueBao.thoiGianNgoaiMang * 3000.0;
return cuocNoiMang + cuocNgoaiMang;
}

int demThueBaoTraTruoc(struct ThueBao danhSachThueBao[], int soLuongThueBao) {
int count = 0;
for (int i = 0; i < soLuongThueBao; i++) {
if (strcmp(danhSachThueBao[i].loaiThueBao, "TT") == 0) {
count++;
}
}
return count;
}

int main() {
struct ThueBao danhSachThueBao[MAX_SUBSCRIBERS];
int soLuongThueBao = 0;
int luaChon;
char hoTenCanTim[50];
char loaiCanTim[3];
int nam;
do {
    printf("\n========== MENU ==========\n");
    printf("1. Nhap thong tin cac thue bao\n");
    printf("2. Xuat thong tin cac thue bao\n");
    printf("3. Them mot thue bao vao danh sach\n");
    printf("4. Sap xep danh sach thue bao theo ma thue bao\n");
    printf("5. Tim thue bao theo ho ten chu thue bao\n");
    printf("6. Xuat thue bao theo loai\n");
    printf("7. Xuat thue bao dang ky sau nam\n");
    printf("8. Tinh cuoc phi cua moi thue bao\n");
    printf("9. Dem so luong thue bao tra truoc\n");
    printf("0. Thoat\n");
    printf("Chon chuc nang: ");
    scanf("%d", &luaChon);

    switch (luaChon) {
        case 1:
            printf("Nhap thong tin cac thue bao:\n");
            themThueBao(danhSachThueBao, &soLuongThueBao);
            break;
        case 2:
            printf("Xuat thong tin cac thue bao:\n");
            for (int i = 0; i < soLuongThueBao; i++) {
                xuatThongTinThueBao(danhSachThueBao[i]);
            }
            break;
        case 3:
            printf("Them mot thue bao moi:\n");
            themThueBao(danhSachThueBao, &soLuongThueBao);
            break;
        case 4:
            printf("Sap xep danh sach thue bao theo ma thue bao:\n");
            sapXepTheoMaThueBao(danhSachThueBao, soLuongThueBao);
            break;
        case 5:
            printf("Nhap ho ten chu thue bao can tim: ");
            scanf("%s", hoTenCanTim);
            timTheoHoTen(danhSachThueBao, soLuongThueBao, hoTenCanTim);
            break;
        case 6:
            printf("Nhap loai thue bao can xuat (TT/TS): ");
            scanf("%s", loaiCanTim);
            xuatTheoLoai(danhSachThueBao, soLuongThueBao, loaiCanTim);
            break;
        case 7:
            printf("Nhap nam: ");
            scanf("%d", &nam);
            xuatTheoDangKySauNam(danhSachThueBao, soLuongThueBao, nam);
            break;
        case 8:
            printf("Cuoc phi cua tung thue bao:\n");
            for (int i = 0; i < soLuongThueBao; i++) {
                printf("Cuoc phi cua thue bao %s: %.2f VND\n", danhSachThueBao[i].maThueBao, tinhCuocPhi(danhSachThueBao[i]));
            }
            break;
        case 9:
            printf("So luong thue bao tra truoc: %d\n", demThueBaoTraTruoc(danhSachThueBao, soLuongThueBao));
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
