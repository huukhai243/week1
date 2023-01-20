#include<stdio.h>
 int main(){
	int A[100];
	int N, i;
	printf("So phan tu : "); scanf("%d",&N);
	{	int k = 0,i, j, t; 
	for(i=0;i < N - 1; i++)
		for(j=i+1;j < N ; j++)
		  if(A[i] > A[j]){
			t = A[j];A[j] = A[i];A[i]=t;
		  }	
	printf("Phan tu moi:"); scanf("%d",&k);
	i = N;
	while( (i > 0) &&(A[i-1] > k) ){
		A[i] = A[i-1];
		i--;
	}
	A[i] = k;
	N++;
}
	for(i=0; i < N; i ++)	printf("%4d",A[i]);
	
}
