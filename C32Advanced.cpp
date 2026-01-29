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
long long gcd (long long a, long long b)
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
	//p,q cang lon thi giai ma cang de dung
	int p,q;
	do
	{
		p = rand()%(399) + 101;
	} while(checkPrimeMillerRabin(p) == false);
	do
	{
		q = rand()%(399) + 101;
	} while (q == p || checkPrimeMillerRabin(q) == false);
	printf("p = %d\nq = %d\n",p,q);
	
	long long n = p*q;
	printf("n = %lld\n",n);
	
	long long phiN = (p-1) * (q-1);
	printf("phi(n) = %lld\n",phiN);
	//chon 1 so e nguyen to cung nhau voi phiN, 1<=e<=phiN-1
	long long e;
	do
	{
		e = rand()%(phiN-1) + 1;
	} while (gcd(e,phiN) != 1);
	printf("e= %lld\n",e);
	//su dung euclid mo rong de tinh nghich dao d = e^-1 mod phiN
	long long d = inverse_modul(e,phiN);
	printf("d=%lld\n",d);
	
	long long sbd;
	printf("\nNhap SBD: ");
	scanf("%lld", &sbd);
	long long m = sbd + 123;
	printf("thong diep m ban dau: %lld\n",m);
	long long encode_c = nhanBinhPhuongCoLap(m,e,n);
	long long decode_m = nhanBinhPhuongCoLap(encode_c,d,n);
	
	printf("Ban ma c: %lld\n",encode_c);
	printf("Giai ma m: %lld\n",decode_m);
	return 0;
}
