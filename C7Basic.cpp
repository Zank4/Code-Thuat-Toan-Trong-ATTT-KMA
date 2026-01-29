#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int nhanBinhPhuongCoLap(long long a, long long k, long long n) // a^k mod n
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
	if(n%2==0)
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
long long reverse(long long a)
{
	long long x = 0;
	while(a>0)
	{
		long long digit = a%10;
		x = x*10 + digit;
		a /= 10;
	}
	return x;
}

bool isEmirp(long long x)
{
	if (checkPrimeFermat(x) == true && checkPrimeFermat(reverse(x)) == true)
	{
		return true;
	}
	return false;
}
int main()
{
	long long n;
	scanf("%lld", &n);
	srand(time(NULL));
	for (long long i =2; i<=n; i++)
	{
		if (isEmirp(i) == true)
		{
			printf("Emirp: %lld\n",i);
		}
	}
	return 0;
}
