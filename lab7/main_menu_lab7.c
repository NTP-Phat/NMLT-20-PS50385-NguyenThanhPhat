#include <stdio.h>
#include <string.h>
#include <ctype.h>

// =======================
// KHAI BAO HAM
// =======================

void demNguyenAmPhuAm();
void dangNhap();
void sapXepChuoi();
void doiThapPhanSangNhiPhan();

// =======================
// HAM MAIN
// =======================

int main()
{
    int chon;

    do
    {
        printf("\n");
        printf("+-----------------------------------------------+\n");
        printf("|           MENU CHUONG TRINH LAB 7             |\n");
        printf("+-----------------------------------------------+\n");
        printf("| 1. Dem Nguyen am va Phu am trong chuoi       |\n");
        printf("| 2. Dang nhap he thong (User & Password)      |\n");
        printf("| 3. Sap xep danh sach Chuoi theo Alphabet      |\n");
        printf("| 4. Chuyen doi so Thap phan sang Nhi phan      |\n");
        printf("| 5. Thoat chuong trinh                         |\n");
        printf("+-----------------------------------------------+\n");

        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        switch (chon)
        {
            case 1:
                demNguyenAmPhuAm();
                break;

            case 2:
                dangNhap();
                break;

            case 3:
                sapXepChuoi();
                break;

            case 4:
                doiThapPhanSangNhiPhan();
                break;

            case 5:
                printf("\nThoat chuong trinh!\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }

    } while (chon != 5);

    return 0;
}


// =================================================
// 1. DEM NGUYEN AM VA PHU AM
// =================================================

void demNguyenAmPhuAm()
{
    char chuoi[100];
    int nguyenAm = 0;
    int phuAm = 0;
    int i;

    getchar();

    printf("\nNhap chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    for (i = 0; chuoi[i] != '\0'; i++)
    {
        char c = tolower(chuoi[i]);

        if (c >= 'a' && c <= 'z')
        {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u')
            {
                nguyenAm++;
            }
            else
            {
                phuAm++;
            }
        }
    }

    printf("So nguyen am: %d\n", nguyenAm);
    printf("So phu am: %d\n", phuAm);
}


// =================================================
// 2. DANG NHAP
// =================================================

void dangNhap()
{
    char username[50];
    char password[50];

    printf("\n===== DANG NHAP =====\n");

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "123456") == 0)
    {
        printf("Dang nhap thanh cong!\n");
    }
    else
    {
        printf("Sai username hoac password!\n");
    }
}


// =================================================
// 3. SAP XEP DANH SACH CHUOI
// =================================================

void sapXepChuoi()
{
    char ds[100][100];
    char temp[100];
    int n;
    int i, j;

    printf("\n===== SAP XEP CHUOI =====\n");

    printf("Nhap so luong chuoi: ");
    scanf("%d", &n);

    getchar();

    for (i = 0; i < n; i++)
    {
        printf("Nhap chuoi %d: ", i + 1);
        fgets(ds[i], sizeof(ds[i]), stdin);

        // Xoa ky tu xuong dong
        ds[i][strcspn(ds[i], "\n")] = '\0';
    }

    // Sap xep tang dan
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(ds[i], ds[j]) > 0)
            {
                strcpy(temp, ds[i]);
                strcpy(ds[i], ds[j]);
                strcpy(ds[j], temp);
            }
        }
    }

    printf("\nDanh sach sau khi sap xep:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, ds[i]);
    }
}


// =================================================
// 4. DOI THAP PHAN SANG NHI PHAN
// =================================================

void doiThapPhanSangNhiPhan()
{
    int n;
    int a[100];
    int i = 0;
    int j;

    printf("\n===== DOI THAP PHAN SANG NHI PHAN =====\n");

    printf("Nhap so thap phan: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Nhi phan: 0\n");
        return;
    }

    while (n > 0)
    {
        a[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Nhi phan: ");

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", a[j]);
    }

    printf("\n");
}