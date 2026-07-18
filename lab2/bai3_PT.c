#include <stdio.h>
int main (){
    int a,b;
    float x;
    printf("nhap a,b:");
    scanf("%d%d",&a,&b);
    if (a==0)
    {
        if(b==0){
            printf("PT vo so nghiem");
        }else{

        printf("PT vo nghiem.\n");
        }

    }else{
        x = -(float)b/a;
        printf("Phuong trinh %dx+%d = 0 co nghiem x= %.2f\n",a,b,x);
    }
    


    return 0;
}