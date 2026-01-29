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
	long long n;
	printf("Nhap so phan tu n: ");
	scanf("%lld", &n);
	long long a[n];
	for (long long i=0; i<n; i++)
	{
		long long z;
		do
		{
			z = rand()%(100-1) + 2;//sinh snt tu 2-100
		} while (checkPrimeMillerRabin(z) == false);
		a[i] = z;
	}
	//in ra mang a
	printf("mang a:\n");
	for (long long i=0; i<n; i++)
		printf("%lld ",a[i]);
		
	//tinh kc nho nhat giua 2 so bat ki
	long long distance = abs(a[1] - a[0]);
	long long M = a[0];
	long long N = a[1];
	for (long long i=0; i<n-1; i++)
	{
		for (long long j=i+1; j<n; j++)
		{
			if (abs(a[j] - a[i]) < distance)
			{
				distance = abs(a[j] - a[i]);
				M = a[i];
				N = a[j];
			}
		}
	}
	printf("\nKhoang cach nho nhat la %d giua 2 so %lld va %lld",distance,M,N);
	return 0;
}
