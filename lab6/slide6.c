#include <stdio.h> 
#define n 5
int main(){
    // int n = 5;
    // int A [n];
    // // nhap mang a
    // for(int i = 0 ; i<n; i++){
    //     printf("nhap A[%d] = ",i);
    //     scanf("%d", &A[i]);
    // }

    // // xuat mang a
    // for (int i = 0; i < n; i++)
    // {
    //     printf("PT[%d] %d\n", i,A[i]);
    // }
    // // cap nhat so le se cong 1
    // for (int i = 0; i < n; i++)
    // {
    //     if (A[i]%2!=0)
    //     A[i]++;
        
    // }
    //  // xuat mang a
    // for (int i = 0; i < n; i++)
    // {
    //     printf("PT[%d] %d\n", i,A[i]);
    // }
    
    // int d=3, c=4;
    // int B[3][4];
    // for (int i = 0; i < d; i++)
    // {
    //    for (int j = 0; j < c; j++)
    //    {
    //     printf("B[%d,%d] = ",i,j);
    //     scanf("%d", &B[i][j]);
    //    }
       
    // }
    // // xuat 
    //  for (int i = 0; i < d; i++)
    // {
    //    for (int j = 0; j < c; j++)
    //    {
    //     printf("B[%2d,%2d] = %3d\t ",B[i][j]);
    //    }
    //    printf("\n");
    // }
    

    // int B[n];

    // // sắp xếp
    // for(int i = 0; i<n-1;i++){
    //     for (int j = i++; j<n;j++)
    //     {
    //         if (B[j]<B[i])
    //         {
    //             int temp = B[i];
    //             B[i] = B[j];
    //             B[j] = temp;
    //         }
            
    //     }
        
    // }

    // printf("xuat mang B sau khi sap xep");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("B[%d]");
    // }
    


    int C[n][n] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if ((i==0) || i== (n-1) || (j==0 || j==(n-1)))
           {
             printf("%d\t", C[i][j]);
           }else{
            printf("  \t");
           }
           
        }
        printf("\n");
    }
    
        
    

return 0;

}