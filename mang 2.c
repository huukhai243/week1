#include <stdio.h> 
int main (){
    int A[10000],i,j,n,tmp,B[1000],k,p,q,chiso;
    printf(" nhap so phan tu cua mang :"); scanf("%d", &n);
    for(int i = 0; i<n;i++) {
        printf("nhap phan tu thu %d cua mang :", i);
        scanf("%d", &A[i]);
    } for (int i = 0; i<n; i++) {
        for( int j = i+1; j<n; j++) {
            if(A[i] > A[j]) {
                tmp = A[i];
                A[i] = A[j];
                A[j]= tmp;
            }
        }
    }
    printf("mang sau khi da sap xep theo thu tu lon dan  la");
    for(int i = 0; i<n; i++) {
        printf ("%d ", A[i]);
    }
    printf("mhap so k :"); scanf("%d",&k);
    while ( int i = -1) {
        i++;
        if (A[i] > k ) {
            chiso= i;
            for( int p = 0; p< i;p++) {
                B[p]=A[p];
            }
            for(int q = i; q<n; q++) {
                B[q+1]=A[q];
            }
            B[i]= k;
                for( int i= 0; i<= n; i ++) {
        printf("%d ", B[i]);
        break;
        }

    } 
 
        
    }
    return 0;    
}
