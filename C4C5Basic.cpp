#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
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
	if (n%2==0)
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
	long long a,b;
	scanf("%lld%lld", &a, &b);
	int count = 0;
	long long s = 0;
	for (long long i=a; i<=b; i++)
	{
		if (checkPrimeFermat(i)==true)
		{
			count++;
			s+=i;
		}
	}
	printf("so so nguyen to: %d\n", count);
	printf("tong cac so nguyen to: %lld",s);
	return 0;
}
