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

int main()
{
	srand(time(NULL));
	long long A,B,C;
	printf("Nhap A: ");
	scanf("%lld", &A);
	printf("Nhap B: ");
	scanf("%lld", &B);
	printf("Nhap C: ");
	scanf("%lld", &C);
	
	long long x = 0;
	while(1)
	{
		long long value = A*x*x + B*x + C;
		if (checkPrimeFermat(value) == true)
		{
			printf("x min thoa man la: %lld",x);
			break;
		}
		x++;
	}
	
	return 0;
}
