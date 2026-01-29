#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
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
bool checkPrimeMillerRabin(long long n,int t)
{
	if (n<=1)
		return false;
	if (n==2 || n ==3)
		return true;
	if (n%2==0)
		return false;
	
	
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
	long long n;
	printf("Nhap n: ");
	scanf("%lld", &n);
	int t;
	printf("Nhap so lan lap kiem tra t: ");
	scanf("%d",&t);
	float xs = 1 - pow(0.25,t);
	if (checkPrimeMillerRabin(n,t) == true)
	{
		printf("snt\n");
		printf("Xs kiem tra: %f",xs);
	}
	else
	{
		printf("hop so\n");
		printf("Xs kiem tra: %f",xs);

	}
	return 0;
}
