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
long long gcd(long long a, long long b)
{
	long long A = a;
	long long B = b;
	while(B>0)
	{
		long long R = A%B;
		A = B;
		B = R;
	}
	return A;
}
int main()
{
	srand(time(NULL));
	int n;
	printf("Nhap kich thuoc mang a[]: ");
	scanf("%d",&n);
	long long a[n];
	printf("Nhap cac phan tu nguyen duong cua mang a[]:\n");
	for (int i=0; i<n; i++)
	{
		scanf("%lld",&a[i]);
		if(a[i] <=0)
		{
			printf("\nNhap lai");
			return 0;
		}
	}
	int count = 0;
	//tim cac cap i,j
	for (int i=0; i<n; i++)
	{
		for (int j=i; j<n; j++)
		{
			if (checkPrimeMillerRabin(gcd(a[i],a[j]))==true)
			{
				count++;
				printf("Cap so (%lld, %lld)\n",a[i],a[j]);
			}
		}
	}
	printf("Co %d cap so",count);
}
