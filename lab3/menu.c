
#include <stdio.h>
#include <math.h>

void hocLuc();
void giaiPTBacHai();
void tinhTienDien();

int main() {
    int chon;

    do {
        printf("\n+--------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 3             |\n");
        printf("+--------------------------------------------------+\n");
        printf("| 1. Chuc nang tinh hoc luc sinh vien              |\n");
        printf("| 2. Chuc nang giai phuong trinh bac hai           |\n");
        printf("| 3. Chuc nang tinh tien dien tieu thu hang thang  |\n");
        printf("| 4. Thoat chuong trinh                            |\n");
        printf("+--------------------------------------------------+\n");
        printf(">> Chon chuc nang cua ban (1-4): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                hocLuc();
                break;
            case 2:
                giaiPTBacHai();
                break;
            case 3:
                tinhTienDien();
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

/*================ CHUC NANG 1 =================*/

void hocLuc() {
    float diem;

    printf("\nNhap diem sinh vien (0 - 10): ");
    scanf("%f", &diem);

    if (diem < 0 || diem > 10) {
        printf("Diem so nhap vao khong hop le!\n");
    }
    else if (diem >= 9) {
        printf("Hoc luc: Xuat sac\n");
    }
    else if (diem >= 8) {
        printf("Hoc luc: Gioi\n");
    }
    else if (diem >= 6.5) {
        printf("Hoc luc: Kha\n");
    }
    else if (diem >= 5) {
        printf("Hoc luc: Trung binh\n");
    }
    else if (diem >= 3.5) {
        printf("Hoc luc: Yeu\n");
    }
    else {
        printf("Hoc luc: Kem\n");
    }
}

/*================ CHUC NANG 2 =================*/

void giaiPTBacHai() {
    float a, b, c;
    float delta, x1, x2;

    printf("\nNhap a: ");
    scanf("%f", &a);

    printf("Nhap b: ");
    scanf("%f", &b);

    printf("Nhap c: ");
    scanf("%f", &c);

    if (a == 0) {

        if (b == 0) {

            if (c == 0) {
                printf("Phuong trinh co vo so nghiem.\n");
            } else {
                printf("Phuong trinh vo nghiem.\n");
            }

        } else {
            printf("Phuong trinh co nghiem x = %.2f\n", -c / b);
        }

    } else {

        delta = b * b - 4 * a * c;

        if (delta < 0) {
            printf("Phuong trinh vo nghiem.\n");
        }
        else if (delta == 0) {
            printf("Phuong trinh co nghiem kep x = %.2f\n", -b / (2 * a));
        }
        else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }
}

/*================ CHUC NANG 3 =================*/

void tinhTienDien() {
    int kWh;
    float tien = 0;

    printf("\nNhap so kWh dien tieu thu: ");
    scanf("%d", &kWh);

    if (kWh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }

    if (kWh <= 50) {
        tien = kWh * 1678;
    }
    else if (kWh <= 100) {
        tien = 50 * 1678
             + (kWh - 50) * 1734;
    }
    else if (kWh <= 200) {
        tien = 50 * 1678
             + 50 * 1734
             + (kWh - 100) * 2014;
    }
    else if (kWh <= 300) {
        tien = 50 * 1678
             + 50 * 1734
             + 100 * 2014
             + (kWh - 200) * 2536;
    }
    else if (kWh <= 400) {
        tien = 50 * 1678
             + 50 * 1734
             + 100 * 2014
             + 100 * 2536
             + (kWh - 300) * 2834;
    }
    else {
        tien = 50 * 1678
             + 50 * 1734
             + 100 * 2014
             + 100 * 2536
             + 100 * 2834
             + (kWh - 400) * 2927;
    }

    printf("Tien dien phai tra: %.0f VND\n", tien);
}