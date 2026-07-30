#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int chon;

    do
    {
        printf("\n================ MENU ================\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Tinh lai suat vay ngan hang\n");
        printf("6. Sap xep thong tin sinh vien\n");
        printf("7. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("======================================\n");
        printf("Nhap lua chon: ");
        scanf("%d",&chon);

        switch(chon)
        {
            case 1:
            // chức năng 1: kiểm tra số nguyên tố
                    {
                        int n, i, dem = 0;

                        printf("Nhap so nguyen: ");
                        scanf("%d", &n);

                        if(n < 2)
                        {
                            printf("%d khong phai la so nguyen to\n", n);
                        }
                        else
                        {
                            for(i = 1; i <= n; i++)
                            {
                                if(n % i == 0)
                                    dem++;
                            }

                            if(dem == 2)
                                printf("%d la so nguyen to\n", n);
                            else
                                printf("%d khong phai la so nguyen to\n", n);
                        }

                        break;
                    };
                break;

            case 2: {
                // chức năng 2: Tìm Ước số chung và bội số chung của 2 số
                        int a, b, x, y, ucln, bcnn;

                        printf("Nhap so thu nhat: ");
                        scanf("%d", &a);

                        printf("Nhap so thu hai: ");
                        scanf("%d", &b);

                        x = a;
                        y = b;

                        while(y != 0)
                        {
                            int du = x % y;
                            x = y;
                            y = du;
                        }

                        ucln = x;
                        bcnn = (a * b) / ucln;

                        printf("UCLN = %d\n", ucln);
                        printf("BCNN = %d\n", bcnn);

                        break;
                    }
                break;

            case 3:
            // karaoke giảm giá 10% từ 14h-17h
            // sau 3h, các giờ tiếp theo giảm 30%
                {
                    int vao, ra;
                    float tien;

                    printf("Nhap gio vao: ");
                    scanf("%d", &vao);

                    printf("Nhap gio ra: ");
                    scanf("%d", &ra);

                    tien = (ra - vao) * 150000;

                    if(vao >= 14 && vao <= 17)
                        tien *= 0.9;

                    if((ra - vao) > 3)
                        tien -= (ra - vao - 3) * 150000 * 0.3;

                    printf("Tien phai tra: %.0f VND\n", tien);

                    break;
                }
                break;

            case 4:
            // tính tiền điện
                {
                    int so;
                    float tien = 0;

                    printf("Nhap so kWh: ");
                    scanf("%d", &so);

                    if(so <= 50)
                        tien = so * 1678;
                    else if(so <= 100)
                        tien = 50 * 1678 + (so - 50) * 1734;
                    else if(so <= 200)
                        tien = 50 * 1678 + 50 * 1734 + (so - 100) * 2014;
                    else if(so <= 300)
                        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (so - 200) * 2536;
                    else if(so <= 400)
                        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (so - 300) * 2834;
                    else
                        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (so - 400) * 2927;

                    printf("Tien dien = %.0f VND\n", tien);

                    break;
                }
                break;

            case 5:
            // tính lãi suất
                {
                    float tienVay = 500000000;
                    float goc = tienVay / 288;
                    float lai;

                    printf("Thang\tGoc\t\tLai\t\tCon lai\n");

                    for(int i = 1; i <= 12; i++)
                    {
                        lai = tienVay * 0.0072;

                        printf("%2d\t%.0f\t%.0f\t%.0f\n",
                            i, goc, lai, tienVay - goc);

                        tienVay -= goc;
                    }

                    break;
                }
                break;

            case 6:
            // sắp xếp sinh viên
                {
                    struct SinhVien
                    {
                        char ten[50];
                        float diem;
                    };

                    struct SinhVien sv[50], temp;
                    int n, i, j;

                    printf("Nhap so sinh vien: ");
                    scanf("%d", &n);

                    getchar();

                    for(i = 0; i < n; i++)
                    {
                        printf("Ten: ");
                        fgets(sv[i].ten, sizeof(sv[i].ten), stdin);

                        printf("Diem: ");
                        scanf("%f", &sv[i].diem);
                        getchar();
                    }

                    for(i = 0; i < n - 1; i++)
                    {
                        for(j = i + 1; j < n; j++)
                        {
                            if(sv[i].diem < sv[j].diem)
                            {
                                temp = sv[i];
                                sv[i] = sv[j];
                                sv[j] = temp;
                            }
                        }
                    }

                    printf("\nDanh sach sau sap xep:\n");

                    for(i = 0; i < n; i++)
                    {
                        printf("%sDiem: %.2f\n", sv[i].ten, sv[i].diem);
                    }

                    break;
                }
                break;

            case 7:
            // tính toán phân số 
                {
                    int a, b, c, d;

                    printf("Nhap tu va mau phan so 1: ");
                    scanf("%d%d", &a, &b);

                    printf("Nhap tu va mau phan so 2: ");
                    scanf("%d%d", &c, &d);

                    printf("Tong = %d/%d\n", a * d + b * c, b * d);
                    printf("Hieu = %d/%d\n", a * d - b * c, b * d);
                    printf("Tich = %d/%d\n", a * c, b * d);
                    printf("Thuong = %d/%d\n", a * d, b * c);

                    break;
                }
                break;

            case 0:
                printf("Cam on!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    }while(chon!=0);

    return 0;
}