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
	if (n==2 || n==3)
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
				{
					return false; //la Hop So
				}
					
				j++;
			}
			if (y != n-1)
			{
				return false; //la Hop So
			}
				
		}
	}
	return true; //la Nguyen To
}

int gcd(long long a, long long b)
{
	long long A = a;
	long long B = b;
	while (B>0)
	{
		long long R = A % B;
		A = B;
		B = R;
	}
	return A;
}
bool isCarmichael (long long n)
{
	if (checkPrimeMillerRabin(n) == true) //la snt chu kp hop so
	{
		return false;
	}
		
	for (int b=2; b<n; b++) // cac so b TM b^n-1 = 1 (mod n) => cac so b < n
	{
		if (gcd(n,b) == 1) //b va n nguyen to cung nhau
		{
			long long z = nhanBinhPhuongCoLap(b,n-1,n);
			if (z != 1)
			{
				return false;
			}
			
		}
	}
	return true;
	
}
int main()
{
	srand(time(NULL));
	long long N;
	scanf("%lld", &N);
	if (N <0 || N> 10000)
	{
		printf("Nhap lai 0<=N<=10000");
		return 0;
	}
	printf("Cac so Carmichael nho hon %d: \n",N);
	for (long long i=2; i<N; i++) //vi so carmichael ko bao gom so 1 nen lap tu 2
	{
		if (isCarmichael(i) == true)
		{
			printf("%lld ", i);
		}
	}
	return 0;
}
