#include <stdio.h>
#include <stdbool.h>
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
	if (n == 2 || n==3)
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

long long gcd(long long a, long long b)
{
	long long A = a;
	long long B = b;
	while (B>0)
	{
		long long R = A%B;
		A=B;
		B=R;
	}
	return A;
}
int main()
{
	srand(time(NULL));
	for (long long i=1; i<=998; i++)
	{
		for (long long j=i+1; j<=999; j++)
		{
			if (checkPrimeFermat(gcd(i,j)) == true)
			{
				printf("Cap so: %lld %lld\n",i,j);
			}
		}
	}
	return 0;
}
