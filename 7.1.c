#include<stdio.h>

typedef int ElementType;

ElementType recurBinSearch(ElementType arr[], int p, int r, ElementType num) { 
   if (p <= r) { 
      int mid = (p + r)/2; 
      if (arr[mid] == num)   
         return mid ; 
      if (arr[mid] > num)  
         return recurBinSearch(arr, p, mid-1, num);            
      if (arr[mid] < num)
         return recurBinSearch(arr, mid+1, r, num); 
   } 
   return -1; 
} 

int main() { 

   ElementType arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40}; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   ElementType num = 33; 
   ElementType index = recurBinSearch(arr, 0, n-1, num); 

   if(index == -1)
      printf("%d is not present in the array",num);
   else
      printf("%d is present at index %d in the array",num,index); 
   return 0; 
}
