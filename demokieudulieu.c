#include <stdio.h>

int main(){

    unsigned short a,b;
    a = 65534;
    for (int i = 0; i < 5; i++)
    {
        b= a + i;
        printf("cộng %d :\t %d\n",i, b);
    }
    

    return 0;
}