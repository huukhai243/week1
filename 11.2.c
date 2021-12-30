#include<stdio.h>
#include<time.h>
void input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void output(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void insertionSort(int a[], int n)
{
    int i, t, j, dem = 0;
	for (i = 1; i < n; i++)
	{
		t = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > t)
		{
			a[j + 1] = a[j];
			j = j - 1;

		}
		a[j + 1] = t;
	}
   
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
	int i=low-1; 
  	int j;
    for (j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void Random(int a[], int n)
{
	int i;
	srand(time(NULL));
    for (i = 0; i <n; i++)
    {
        a[i] = rand()%100;
    }
}
int main()
{
	int a[10000],n;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	input(a,n);
	//Insertionsort time
	clock_t start1, end1;
	start1 = clock();
	insertionSort(a, n);
	output(a,n);
	end1 = clock();
	double time1 = (double)(end1 - start1) /(double) CLOCKS_PER_SEC;
	printf("\nInsertSort: %lf sec\n",time1);
	//Quicksort time
	clock_t start2, end2;
	start2 = clock();
	quickSort(a,0,n-1);
	output(a,n);
	end2 = clock();
	double time2=(double)(end2 - start2) / (double)CLOCKS_PER_SEC;
	printf("\nQuickSort: %lf sec\n",time2);
	return 0;
}
