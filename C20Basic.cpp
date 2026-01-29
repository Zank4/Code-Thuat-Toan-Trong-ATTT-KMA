#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
long long gcd(long long a, long long b)
{
	long long A = a;
	long long B = b;
	long long R;
	while(B>0)
	{
		R = A%B;
		A = B;
		B = R;
	}
	return A;
}
int main()
{
	long long M,N,D;
	printf("Nhap M: ");
	scanf("%lld", &M);
	printf("Nhap N: ");
	scanf("%lld", &N);
	printf("Nhap D: ");
	scanf("%lld", &D);
	if (M<=0 || M>=N || D>=1000)
	{
		printf("Nhap lai D<1000; M>0; M<N");
		return 0;
	}
	
	for (long long i=M; i<=N; i++)
	{
		for (long long j=i; j<=N; j++)
		{
			if (gcd(i,j) == D)
				printf("Cap so: (%lld,%lld)\n",i,j);
		}
	}
	return 0;
}
