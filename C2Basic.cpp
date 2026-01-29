#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
long long nhanBinhPhuongCoLap(long long a, long long k, long long n) //tinh a^k mod n
{
	long long b=1;
	long long A = a;
	if(k%2 == 1)
	{
		b = a;
	}
	k /= 2;
	while(k>0)
	{
		A = (A*A) % n;
		if (k%2 == 1)
		{
			b = (A*b)%n;
		}
		k /= 2;
	}	
	return b;
}
bool checkPrimeFermat(long long n)
{
	if (n <=1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if(n%2==0)
		return false;
	int t = 5;
	for (int i=1; i<= t; i++)
	{
		long long a = ( rand() % (n-3) ) + 2;
		long long r = nhanBinhPhuongCoLap(a,n-1,n);
		if (r != 1)
			return false;
	}
	return true;
}
int main()
{
	srand(time(NULL));
	int n;
	printf("Nhap N ( 2 <= N <= 10): ");
	scanf("%d", &n);
	if (n < 2 || n > 10)
	{
		printf("Nhap lai");
		return 0;
	}
	
	long long start = pow(10,n-1);
	long long end = pow(10,n) - 1;
	for (long long i = start; i <= end; i++)
	{
		if (checkPrimeFermat(i) == true)
		{
			printf("%lld\n",i);
		}
	}
	return 0;
}
