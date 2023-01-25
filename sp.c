#include <stdio.h>

void main()
{
	int n, i, tmp, count=0;
	printf("Enter n: ");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		tmp=i;
		while (tmp!=0)
		{
			if (tmp%10==0)
				count++;
			tmp/=10;
		}
	}
	printf("The number of digit 0 appeared is %d\n",count);
}
