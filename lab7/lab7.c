#include <stdio.h>
#include <string.h>

int main() {
    char string1[20] = "fPT POlyTEchnic HCM";   // = {'A','B','C'};
    char string2[20] = " ";

    printf("Chuoi1: %s\n",string1);
    strlwr(string1);
    printf("Chuoi2: %s\n", strlwr(string1));


    // printf("Nhap ho ten: ");
    // // scanf("%s", hoTen);
    // gets(hoTen);

    // printf("Nhap nghe nghiep: ");
    // // scanf("%s", ngheNghiep);
    // gets(ngheNghiep);

    // for (int i = 0; i < strlen(hoTen); i++) {
    //     printf("%c", i, hoTen[i]);
    // }

    // printf("\n\n");

    // for (int i = 0; i < strlen(ngheNghiep); i++) {
    //     printf("%c", i, ngheNghiep[i]);
    // }

    return 0;
}