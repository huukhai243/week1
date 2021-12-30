#include <stdio.h>
#include <string.h>
typedef struct{
	char name[31];
	char tel[12];
	char mail[31];
}Address;
Address arr[100];
int input()
{
	FILE *fp = fopen("address.dat","rb");
	if (fp==NULL)
		return 0;
	fread(arr,sizeof(Address),10,fp);
	fclose(fp);
	return 1;
}
void quicksort(int first, int last)
{
	int pivot=last-1;
	Address tmp;
	int i;
	if (last<=first)
		return;
	for (i=0;i<(last-first);i++)
		if (strcmp(arr[i].name,arr[last].name)>0)
		{
			tmp=arr[i];
			arr[i]=arr[privot];
			arr[pivot--]=tmp;
		}
	tmp=arr[last];
	arr[last]=arr[privot];
	arr[pivot]=tmp;
	quicksort(first,pivot-1);
	quicksort(pivot+1,last);
}
void out()
{
	FILE *fp=fopen("sort.dat","a+b");
	fwrite(arr,sizeof(Address),10,fp);
	fclose(fp);
}
int main()
{
	int found;
	char search[31];
	if (input()==0)
	{
		printf("Cannot open the address folder.\n");
		return 1;
	}
	quicksort(0,9);
	out();
	printf("Sorted!\n");
	return 0;
}
