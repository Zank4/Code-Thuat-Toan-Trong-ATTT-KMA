#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
	if (n%2 == 0)
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

void arrayPrime (long long n, long long a[], int* index)
{
	for (long long i=2; i<=n; i++)
	{
		if (checkPrimeFermat(i) == true)
		{
			a[*index] = i;
			(*index)++;
		}
	}
}
int main()
{
	srand(time(NULL));
	long long n;
	scanf("%lld", &n);
	long long a[n];
	int index = 0;
	arrayPrime(n,a,&index);
	for (int i=0; i<index-1; i++)
	{
		for (int j=i+1; j<index; j++)
		{
			if (checkPrimeFermat(a[i] + a[j])==true && checkPrimeFermat(a[j] - a[i])==true)
			{
				printf("%lld %lld\n",a[i],a[j]);
			}
		}
	}
	return 0;
}
