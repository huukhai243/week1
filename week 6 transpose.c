#include<stdio.h>
int search(int r[], int n,int key )
{
	int i;
	int tempr;
	for ( i=0; i<n-1 && r[i] != key; i++ )
	{
		if ( key == r[i] )
		{
			if ( i>0 )
			{
				tempr = r[i];
				r[i] = r[i-1];
				r[--i] = tempr;
			}
		}
		return i;
	}
	return -1;
}
int main()
{
    int x, a[100];
    int i,n;
    printf("Enter number of elements:  ");
    scanf_s("%d",&n);
    for (i = 0; i < n; ++i)
    {
        printf("Enter number %d: ", i + 1);
        scanf_s("%d", &a[i]);
    }
    printf("Enter value need to find: ");
    scanf_s("%d", &x);

    int idx = search(a, n, x);
    if (idx == -1)
        printf("No found\n");
    else
        printf("%d had index: %d\n",x,idx+1);
    return 0;
}
