#include <stdio.h>
int main() {
    int arr[100];
    int i, j, x, pos, n, temp;
    printf("So phan tu trong mang:"); 
	scanf("%d", &n);
    for (i = 1; i < n; i++){
        printf("input arr[%d]:", i);
        scanf("\n %d", &arr[i]);
    }
    printf("Nhap day ban dau: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for(i = 0; i<n-1; i++){
        for(j = i+1; j<n; j++){                    
            if(arr[j]<arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("Nhap day sau xu ly: ");
    for(i = 0;i < n ;i++)    {
		printf("%d ",arr[i]);
	}     
	printf("\n");            
    printf("Vi tri cua phan tu can chen:"); 
    scanf("%d", &pos);
    printf("Nhap phan tu can chen:");
    scanf("%d", &x);
    n++;
    for (i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = x;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

