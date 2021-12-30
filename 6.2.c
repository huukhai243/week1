#include<stdio.h>
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int x, a[10];
    int i;
    for (i = 0; i < 10; ++i)
    {
        printf("Enter number %d: ", i + 1);
        scanf_s("%d", &a[i]);
    }
    printf("Enter value need to find: ");
    scanf_s("%d", &x);

    int idx = search(a, 10, x);
    if (idx == -1)
        printf("0\n");
    else
        printf("%d had index: %d\n",x,idx+1);


    return 0;
}
