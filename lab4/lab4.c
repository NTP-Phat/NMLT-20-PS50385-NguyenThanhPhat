#include <stdio.h>

void chucNang1();
void chucNang2();
void chucNang3();

int main() {
    int chon;

    do {
        printf("\n+------------------------------------------+\n");
        printf("|         MENU CHUONG TRINH LAB 4          |\n");
        printf("+------------------------------------------+\n");
        printf("| 1. Tinh trung binh cac so chia het cho 2 |\n");
        printf("| 2. Kiem tra so nguyen to                 |\n");
        printf("| 3. Kiem tra so chinh phuong              |\n");
        printf("| 4. Thoat chuong trinh                    |\n");
        printf("+------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                chucNang1();
                break;
            case 2:
                chucNang2();
                break;
            case 3:
                chucNang3();
                break;
            case 4:
                printf("Da thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 4);

    return 0;
}

/*================ CHUC NANG 1 ================*/
void chucNang1() {
    int min, max;
    int tong = 0;
    int dem = 0;
    float trungBinh;
    int i;

    printf("\nNhap min: ");
    scanf("%d", &min);

    printf("Nhap max: ");
    scanf("%d", &max);

    if (min > max) {
        printf("Loi: min phai nho hon hoac bang max!\n");
        return;
    }

    for (i = min; i <= max; i++) {
        if (i % 2 == 0) {
            tong += i;
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so nao chia het cho 2.\n");
    } else {
        trungBinh = (float)tong / dem;
        printf("Tong = %d\n", tong);
        printf("So luong = %d\n", dem);
        printf("Trung binh = %.2f\n", trungBinh);
    }
}

/*================ CHUC NANG 2 ================*/
void chucNang2() {
    int x, i;
    int laNT = 1;

    printf("\nNhap so nguyen x: ");
    scanf("%d", &x);

    if (x < 2) {
        laNT = 0;
    } else {
        for (i = 2; i < x; i++) {
            if (x % i == 0) {
                laNT = 0;
                break;
            }
        }
    }

    if (laNT == 1)
        printf("%d la so nguyen to.\n", x);
    else
        printf("%d khong phai la so nguyen to.\n", x);
}

/*================ CHUC NANG 3 ================*/
void chucNang3() {
    int x, i;
    int laSCP = 0;

    printf("\nNhap so nguyen x: ");
    scanf("%d", &x);

    if (x < 0) {
        printf("%d khong phai la so chinh phuong.\n", x);
        return;
    }

    for (i = 1; i <= x; i++) {
        if (i * i == x) {
            laSCP = 1;
            break;
        }
    }

    if (laSCP == 1)
        printf("%d la so chinh phuong.\n", x);
    else
        printf("%d khong phai la so chinh phuong.\n", x);
}