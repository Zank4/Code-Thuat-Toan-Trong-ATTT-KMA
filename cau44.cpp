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
long long inverse_modul (long long a, long long n) // tinh a^-1 mod n
{
	long long u = a;
    long long v = n;
    long long x1 = 1;
    long long x2 = 0;
    long long q,r,x;
    while(u !=1)
    {
        q = v/u;
        r = v - q*u;
        x = x2 - q*x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    if (x1<0)
        x1 = x1 + n;
    return x1;
}
int main()
{
	srand(time(NULL));
	long long p;
	do
	{
		printf("Nhap snt p: ");
		scanf("%lld", &p);
	} while (checkPrimeMillerRabin(p) == false);
	int n;
	printf("Nhap so phan tu mang a[]: ");
	scanf("%d", &n);
	long long a[n];
	printf("Nhap cac phan tu mang a, 0 < a[i] < p:\n");
	for (int i=0; i<n; i++)
	{
		scanf("%lld", &a[i]);
		if(a[i] <=0 || a[i] >=p)
		{
			printf("Nhap lai 0 < a[i] < p");
			return 0;
		}
	}
	long long b[n];
	for (int i=0; i<n; i++)
	{
		b[i] = inverse_modul(a[i],p);
	}
	printf("Mang b nghich dao cua a:\n");
	for (int i=0; i<n; i++)
	{
		printf("%lld ",b[i]);
	}
	return 0;
}
