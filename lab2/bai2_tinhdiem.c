#include <stdio.h>
int main(){
    short t,l,h;
    float tb;
    t = 7;
    l = 8;
    h = 10;
    tb = 1.0*(t*3+l*2+h)/6; //ep kieu
    printf("Toan: %d Ly: %d Hoa: %d \n",t,l,h);
    printf("Diem trung binh: %f\n",tb);
    return 0;
}