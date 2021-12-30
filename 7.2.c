#include<stdio.h>

int recurBinSearch(int arr[], int p, int r, int num, int* compare) { 
   if ( ++compare  && p <= r) { 
      int mid = (p + r)/2; 
      if ( ++compare  && arr[mid] == num)   
         return mid ; 
      if ( ++compare  && arr[mid] > num)  
         return recurBinSearch(arr, p, mid-1, num, compare);            
      if ( ++compare  && arr[mid] < num)
         return recurBinSearch(arr, mid+1, r, num, compare); 
   } 
   return -1; 
} 

int main() { 

   int arr[101],i;n
   for (i = 0; i < 100; ++i)
      arr[i] = i+1;
      
      
   int n = 100; 
   int num = 36; 
   int compare = 0;
   int index = recurBinSearch(arr, 0, n-1, num, &compare); 

   if(index == -1)
      printf("Not found\n");
   else {
      printf("%d is present at index %d in the array\n",num,index); 
      printf("Number of comaprisons is: %d\n",compare); 
   }
   return 0; 
}
