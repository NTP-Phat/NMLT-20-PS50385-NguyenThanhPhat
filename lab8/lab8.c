#include <stdio.h>
#include <string.h>

int main(){
    // quan ly sinh vien
    int n=1;

    // char maSV1[8];
    // char tenSV1[30];
    // float diemSV1;

    // char maSV2[8];
    // char tenSV2[30];
    // float diemSV2;
    
    // char dsmaSV[40][8];
    // char dstenSV[40][30];
    // float dsdiemSV[40];

struct SinhVien // kieu du lieu moi
{
    char maSV[8];
    char tenSV[30];
    float diemSV;
};

    // struct SinhVien sv3;
    struct SinhVien dsSinhVien[40];
    // nhap du lieu
    for ( int i = 0; i < n; i++)
    {
        printf("nhap maSinhVien[%d]: ", i);
        gets(dsSinhVien[i].maSV);

        printf("nhap tenSinhVien[%d]: ", i);
        gets(dsSinhVien[i].tenSV);

        printf("nhap diemSinhVien[%d]: ", i);
        scanf("%f" ,&dsSinhVien[i].diemSV); // dang co 7.5 enter
        // xu ly enter cho den het
        getchar();
    }
    
    printf("Xuat danh sach sinh vien: \n");
    printf("Ma sinh vien  Ten Sinh Vien  Diem Sinh Vien\n");


    for(int i=0 ; i<n ; i++){
        printf("%-15s %-15s %5.2f\n",dsSinhVien[i].maSV,dsSinhVien[i].tenSV,dsSinhVien[i].diemSV);
    }

    return 0;
}