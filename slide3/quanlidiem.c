#include <stdio.h>
int main(){
    float diem;
    printf("nhap diem: ");
    scanf("%f",&diem);
    if (diem >= 5.0){
        printf("Dau\n");
    }
    else{
        printf("Rot\n");
    }
    if (diem >= 8)
    {
        printf("xep loai gioi \n");
    }else if (diem >= 6.5)
    {
        printf("xep loai kha \n ");
    }else if (diem >= 5){
        printf("xep loai trung binh \n ");
    }else {
        printf("xep loai yeu \n ");
    }
    
    


    
    return 0;
}