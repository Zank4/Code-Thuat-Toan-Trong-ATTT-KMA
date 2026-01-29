#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
long long nhanBinhPhuongCoLap(long long a, long long k, long long n) // a^k mod n
{
	long long b = 1;
	long long A = a;
	if (k%2==1)
	{
		b = a;
	}
	k /= 2;
	while (k>0)
	{
		A = (A*A) % n;
		if (k%2==1)
		{
			b = (A*b) % n;
		}
		k /= 2;
	}
	return b;
}

bool checkPrimeFermat(long long n)
{
	if (n<=1)
		return false;
	if (n==2 || n==3)
		return true;
	if (n%2==0)
		return false;
	int t = 5;
	
	for (int i=1; i<=t; i++)
	{
		long long a = rand()%(n-3) + 2;
		long long r = nhanBinhPhuongCoLap(a,n-1,n);
		if (r!=1)
			return false;
	}
	return true;
}

long long F(long long n)
{
	if(checkPrimeFermat(n) == true)
		return n;
	return 0;
}
int main()
{
	srand(time(NULL));
	long long L,R;
	printf("Nhap L: ");
	scanf("%lld",&L);
	printf("Nhap R: ");
	scanf("%lld",&R);
	if(L<=0 || L>=R || R>=10000)
	{
		printf("Nhap Lai 0<L<R<10000");
		return 0;
	}
	long long tong = 0;
	for (long long i=L; i<=R-1; i++)
	{
		for(long long j=i+1; j<=R; j++)
		{
			printf("F[%lld] * F[%lld] = %lld\n",i,j,F(i)*F(j));
			tong += F(i)*F(j);
		}
	}
	printf("\t\tTong = %lld",tong);
	return 0;
}
