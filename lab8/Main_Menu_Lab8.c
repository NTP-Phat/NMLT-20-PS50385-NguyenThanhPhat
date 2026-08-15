#include <stdio.h>
#include <string.h>

struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

struct SinhVien mangSV[100];
int n = 0;

void nhapXuatSinhVien(struct SinhVien mangSV[], int *n);
void sapXepSinhVien(struct SinhVien mangSV[], int n);
void timKiemSinhVien(struct SinhVien mangSV[], int n);
void xuatHocBong(struct SinhVien mangSV[], int n);

int main() {
    int chon;

    do {
        printf("\n+-----------------------------------------------+\n");
        printf("|      HE THONG QUAN LY SINH VIEN (LAB 8)       |\n");
        printf("+-----------------------------------------------+\n");
        printf("| 1. Nhap va Xuat danh sach sinh vien           |\n");
        printf("| 2. Sap xep sinh vien theo diem TB tang dan   |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV              |\n");
        printf("| 4. Xuat danh sach sinh vien dat hoc bong     |\n");
        printf("| 5. Thoat chuong trinh                         |\n");
        printf("+-----------------------------------------------+\n");

        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                nhapXuatSinhVien(mangSV, &n);
                break;

            case 2:
                sapXepSinhVien(mangSV, n);
                break;

            case 3:
                timKiemSinhVien(mangSV, n);
                break;

            case 4:
                xuatHocBong(mangSV, n);
                break;

            case 5:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 5);

    return 0;
}

void nhapXuatSinhVien(struct SinhVien mangSV[], int *n) {
    int i;

    printf("\nNhap so luong sinh vien: ");
    scanf("%d", n);
    getchar();

    for (i = 0; i < *n; i++) {
        printf("\nSinh vien thu %d\n", i + 1);

        printf("MSSV: ");
        fgets(mangSV[i].mssv, 50, stdin);
        mangSV[i].mssv[strcspn(mangSV[i].mssv, "\n")] = 0;

        printf("Ho ten: ");
        fgets(mangSV[i].tenSV, 50, stdin);
        mangSV[i].tenSV[strcspn(mangSV[i].tenSV, "\n")] = 0;

        printf("Nganh hoc: ");
        fgets(mangSV[i].nganhHoc, 50, stdin);
        mangSV[i].nganhHoc[strcspn(mangSV[i].nganhHoc, "\n")] = 0;

        printf("Diem trung binh: ");
        scanf("%f", &mangSV[i].diemTB);
        getchar();
    }

    printf("\n========== DANH SACH SINH VIEN ==========\n");

    printf("%-15s %-20s %-20s %-10s\n",
           "MSSV", "Ho ten", "Nganh hoc", "Diem");

    for (i = 0; i < *n; i++) {
        printf("%-15s %-20s %-20s %-10.2f\n",
               mangSV[i].mssv,
               mangSV[i].tenSV,
               mangSV[i].nganhHoc,
               mangSV[i].diemTB);
    }
}

void sapXepSinhVien(struct SinhVien mangSV[], int n) {
    int i, j;
    struct SinhVien temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mangSV[i].diemTB > mangSV[j].diemTB) {
                temp = mangSV[i];
                mangSV[i] = mangSV[j];
                mangSV[j] = temp;
            }
        }
    }

    printf("\n===== DANH SACH SAU KHI SAP XEP =====\n");

    printf("%-15s %-20s %-20s %-10s\n",
           "MSSV", "Ho ten", "Nganh hoc", "Diem");

    for (i = 0; i < n; i++) {
        printf("%-15s %-20s %-20s %-10.2f\n",
               mangSV[i].mssv,
               mangSV[i].tenSV,
               mangSV[i].nganhHoc,
               mangSV[i].diemTB);
    }
}

void timKiemSinhVien(struct SinhVien mangSV[], int n) {
    char mssvTim[50];
    int i, found = 0;

    printf("\nNhap MSSV can tim: ");
    fgets(mssvTim, 50, stdin);
    mssvTim[strcspn(mssvTim, "\n")] = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(mangSV[i].mssv, mssvTim) == 0) {
            printf("\n===== TIM THAY SINH VIEN =====\n");
            printf("MSSV      : %s\n", mangSV[i].mssv);
            printf("Ho ten    : %s\n", mangSV[i].tenSV);
            printf("Nganh hoc : %s\n", mangSV[i].nganhHoc);
            printf("Diem TB   : %.2f\n", mangSV[i].diemTB);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Khong tim thay sinh vien co MSSV nay!\n");
    }
}

void xuatHocBong(struct SinhVien mangSV[], int n) {
    int i, found = 0;

    printf("\n===== DANH SACH SINH VIEN DAT HOC BONG =====\n");

    printf("%-15s %-20s %-20s %-10s\n",
           "MSSV", "Ho ten", "Nganh hoc", "Diem");

    for (i = 0; i < n; i++) {
        if (mangSV[i].diemTB >= 8.0) {
            printf("%-15s %-20s %-20s %-10.2f\n",
                   mangSV[i].mssv,
                   mangSV[i].tenSV,
                   mangSV[i].nganhHoc,
                   mangSV[i].diemTB);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Khong co sinh vien nao dat hoc bong!\n");
    }
}