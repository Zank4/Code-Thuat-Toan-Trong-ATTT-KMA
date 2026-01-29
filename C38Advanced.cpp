#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	long long a;
	long long p;
	do
	{
		printf("Nhap a: ");
		scanf("%lld", &a);
		
		printf("Nhap p sao cho UCLN (a,p) = 1:  ");
		scanf("%lld", &p);
	} while (gcd(a,p) != 1);

	printf("Result = %lld",inverse_modul(a,p));
}
