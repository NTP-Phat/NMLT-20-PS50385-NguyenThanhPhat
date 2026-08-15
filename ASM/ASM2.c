
#include <stdio.h>
#include <math.h>

void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();

int main() {
    int chon;

    do {
        menu();
        printf("\nNhap chuc nang: ");
        scanf("%d", &chon);

        switch(chon){
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0: printf("Thoat chuong trinh!\n"); break;
            default: printf("Nhap sai!\n");
        }

    } while(chon != 0);

    return 0;
}

void menu(){
    printf("\n========== MENU ==========\n");
    printf("1. Kiem tra so nguyen\n");
    printf("2. Tim UCLN va BCNN\n");
    printf("3. Tinh tien Karaoke\n");
    printf("4. Tinh tien dien\n");
    printf("5. Doi tien\n");
    printf("6. Lai suat vay ngan hang\n");
    printf("7. Vay tien mua xe\n");
    printf("8. Sap xep sinh vien\n");
    printf("9. Game FPOLY (don gian)\n");
    printf("10. Tinh toan phan so\n");
    printf("0. Thoat\n");
}

void chucNang1(){
    int x,i,nt=1;

    printf("Nhap x: ");
    scanf("%d",&x);

    printf("%d la so nguyen.\n",x);

    if(x<2) nt=0;
    else{
        for(i=2;i<=sqrt(x);i++){
            if(x%i==0){
                nt=0;
                break;
            }
        }
    }

    if(nt) printf("La so nguyen to.\n");
    else printf("Khong phai so nguyen to.\n");

    if(sqrt(x)==(int)sqrt(x))
        printf("La so chinh phuong.\n");
    else
        printf("Khong phai so chinh phuong.\n");
}

void chucNang2(){
    int a,b,x,y,ucln,bcnn;

    printf("Nhap hai so: ");
    scanf("%d%d",&a,&b);

    x=a;
    y=b;

    while(y!=0){
        int t=x%y;
        x=y;
        y=t;
    }

    ucln=x;
    bcnn=a*b/ucln;

    printf("UCLN = %d\n",ucln);
    printf("BCNN = %d\n",bcnn);
}

void chucNang3(){
    int bd,kt;
    float tien;

    printf("Nhap gio bat dau: ");
    scanf("%d",&bd);
    printf("Nhap gio ket thuc: ");
    scanf("%d",&kt);

    if(bd<12||kt>23||bd>=kt){
        printf("Gio khong hop le!\n");
        return;
    }

    int gio=kt-bd;

    if(gio<=3)
        tien=gio*50000;
    else
        tien=150000+(gio-3)*50000*0.7;

    if(bd>=14&&bd<=17)
        tien*=0.9;

    printf("Tien phai tra: %.0f VND\n",tien);
}

void chucNang4(){
    int so;
    float tien=0;

    printf("Nhap so kWh: ");
    scanf("%d",&so);

    if(so<=50)
        tien=so*1678;
    else if(so<=100)
        tien=50*1678+(so-50)*1734;
    else if(so<=200)
        tien=50*1678+50*1734+(so-100)*2014;
    else if(so<=300)
        tien=50*1678+50*1734+100*2014+(so-200)*2536;
    else if(so<=400)
        tien=50*1678+50*1734+100*2014+100*2536+(so-300)*2834;
    else
        tien=50*1678+50*1734+100*2014+100*2536+100*2834+(so-400)*2927;

    printf("Tien dien: %.0f VND\n",tien);
}

void chucNang5(){
    int tien;
    int menhGia[]={500,200,100,50,20,10,5,2,1};

    printf("Nhap so tien: ");
    scanf("%d",&tien);

    for(int i=0;i<9;i++){
        if(tien>=menhGia[i]){
            printf("%d to %d\n",tien/menhGia[i],menhGia[i]);
            tien%=menhGia[i];
        }
    }
}

void chucNang6(){
    float vay,goc,lai,con;

    printf("Nhap so tien vay: ");
    scanf("%f",&vay);

    goc=vay/12;
    con=vay;

    printf("\nThang\tLai\tGoc\tTong\tCon lai\n");

    for(int i=1;i<=12;i++){
        lai=con*0.05;
        printf("%d\t%.0f\t%.0f\t%.0f\t%.0f\n",
        i,lai,goc,lai+goc,con-goc);
        con-=goc;
    }
}

void chucNang7(){
    float xe=500000000;
    float phantram,vay,traTruoc;
    float laiThang=0.072/12;
    int thang=24*12;

    printf("Nhap %% vay: ");
    scanf("%f",&phantram);

    vay=xe*phantram/100;
    traTruoc=xe-vay;

    float traHangThang=vay/thang+vay*laiThang;

    printf("Tra truoc: %.0f VND\n",traTruoc);
    printf("Tra moi thang: %.0f VND\n",traHangThang);
}

struct SinhVien{
    char ten[50];
    float diem;
};

void chucNang8(){
    struct SinhVien sv[20],t;
    int n,i,j;

    printf("Nhap so sinh vien: ");
    scanf("%d",&n);

    getchar();

    for(i=0;i<n;i++){
        printf("Ten: ");
        gets(sv[i].ten);
        printf("Diem: ");
        scanf("%f",&sv[i].diem);
        getchar();
    }

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(sv[i].diem<sv[j].diem){
                t=sv[i];
                sv[i]=sv[j];
                sv[j]=t;
            }

    printf("\nDanh sach:\n");

    for(i=0;i<n;i++){
        printf("%s - %.1f - ",sv[i].ten,sv[i].diem);

        if(sv[i].diem>=9)
            printf("Xuat sac");
        else if(sv[i].diem>=8)
            printf("Gioi");
        else if(sv[i].diem>=6.5)
            printf("Kha");
        else if(sv[i].diem>=5)
            printf("Trung binh");
        else
            printf("Yeu");

        printf("\n");
    }
}

void chucNang9(){
    int so;

    printf("Nhap so (1-10): ");
    scanf("%d",&so);

    if(so==7)
        printf("Chuc mung ban doan dung!\n");
    else
        printf("Chuc ban may man lan sau!\n");
}

void chucNang10(){
    int t1,m1,t2,m2;

    printf("Nhap tu va mau PS1: ");
    scanf("%d%d",&t1,&m1);

    printf("Nhap tu va mau PS2: ");
    scanf("%d%d",&t2,&m2);

    printf("Tong: %d/%d\n",t1*m2+t2*m1,m1*m2);
    printf("Hieu: %d/%d\n",t1*m2-t2*m1,m1*m2);
    printf("Tich: %d/%d\n",t1*t2,m1*m2);
    printf("Thuong: %d/%d\n",t1*m2,m1*t2);
}