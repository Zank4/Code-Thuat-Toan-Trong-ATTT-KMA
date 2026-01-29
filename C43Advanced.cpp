#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

long long nhanBinhPhuongCoLap(long long a, long long k, long long n)
{
	long long b=1;
	long long A = a;
	if (k%2 == 1)
	{
		b = a;
	}
	k /=2;
	while(k>0)
	{
		A = (A*A) % n;
		if (k%2==1)
		{
			b = (A*b) %n;
		}
		k/=2;
	}
	return b;
}
bool checkPrimeMillerRabin(long long n)
{
	if (n<=1)
		return false;
	if (n==2 || n ==3)
		return true;
	if (n%2==0)
		return false;
	
	int t = 5;
	long long N = n-1;
	long long s = 0;
	while (N%2 == 0)
	{
		N /= 2;
		s++;
	}
	long long r = N;
	for (int i=1; i<=t; i++)
	{
		long long a = rand()%(n-3) + 2;
		long long y = nhanBinhPhuongCoLap(a,r,n);
		if (y != 1 && y != n-1)
		{
			int j = 1;
			while(j < s && y != n-1)
			{
				y = (y*y) % n;
				if(y == 1)
					return false; //la Hop So
				j++;
			}
			if (y != n-1)
				return false;//la hop so
		}
	}
	return true; //la Nguyen To
}
int main()
{
	srand(time(NULL));
	long long N;
	printf("Nhap N (0<N<1000): ");
	scanf("%lld", &N);
	if (N<=0 || N>=1000)
	{
		printf("Nhap lai");
		return 0;
	}
	long long p;
	do
	{
		p = rand()%(N-1) + 1; //1<= p <=N-1
	} while (checkPrimeMillerRabin(p) == false);
	
	printf("p = %lld\n",p);
	for (long long a = 1; a<N; a++)
	{
		long long z = nhanBinhPhuongCoLap(a,p,N);
		if (checkPrimeMillerRabin(z) == true)
			printf("a = %lld , result = %lld\n",a,z);
	}
	
	
	return 0;
}
