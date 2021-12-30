#include<stdio.h>

int recurBinSearch(int arr[], int p, int r, int num, int* compare, int* recurCall) { 
   if ( ++compare  && p <= r) { 
      int mid = (p + r)/2; 
      if ( ++compare  && arr[mid] == num)   
         return mid ; 
      if ( ++compare  && arr[mid] > num && ++recurCall)  
         return recurBinSearch(arr, p, mid-1, num, compare, recurCall);            
      if ( ++compare  && arr[mid] < num && ++recurCall)
         return recurBinSearch(arr, mid+1, r, num, compare, recurCall); 
   } 
   return -1; 
} 

int binSearch(int arr[], int n, int target, int* compare) {
   compare = 0;
   if (++ compare && n == 0)
      return -1;
   int l = 0;
   int r = n-1;
   int mid = 0;
   
   while ( ++ compare && l <= r){
      mid = l + (r-l) / 2;
      if (++ compare && arr[mid] == target)
            return mid;
      if (++ compare && arr[mid] >= arr[l]){
            if ( ++ compare && arr[l] <= target && target < arr[mid])
               r = mid - 1;
            else
               l = mid + 1;
      }
      else{
            if (++ compare && arr[mid] < target && target <= arr[r])
               l = mid + 1;
            else
               r = mid-1;
      }
   }
   return -1;
}
int main() {

    int arr[101],i;
    for (i = 0; i < 100; ++i)
        arr[i] = i + 1;
    int n = 100;
    int num = 33;
    int compare = 0;
    int compareRecur = 0;
    int recurCall = 0;
    int index1 = recurBinSearch(arr, 0, n - 1, num, &compareRecur, &recurCall);
    int index2 = binSearch(arr, n, num, &compare);

    if (index1 == -1)
        printf("Not found\n");
    else {
        printf("Recursion binary search \t|\t Binary search\n");
        printf("%d is present at index %d\t|\t", num, index2);
        printf("%d\n", index1);
        printf("Number of comaprisons is: %d\t|\t",compareRecur);
        printf("%d\n", compare);
        printf("Recursion call: %d\t\t|\t 0\n",recurCall);
    }

    return 0;
}
