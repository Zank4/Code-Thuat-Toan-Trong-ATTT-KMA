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
	if (n%2==0 )
		return false;
	long long N = n-1;
	long long s = 0;
	int t = 5;
	while(N%2 == 0)
	{
		N /= 2;
		s++;
	}
	long long r = N;
	for (int i=1; i<=t; i++)
	{
		long long a = rand()%(n-3) + 2;
		long long y = nhanBinhPhuongCoLap (a,r,n);
		if (y!=1 && y!=n-1)
		{
			int j=1;
			while(j <s && y != n-1)
			{
				y = (y*y)%n;
				if (y==1)
					return false;//la hop so
				j++;
			}
			if (y!=n-1)
				return false; //la hop so
		}
	}
	return true; //la nguyen to
}

long long primeClosest(long long x) //x la phan so cua mssv
{
	if (checkPrimeMillerRabin(x) == true)
		return x;//neu chinh x la snt thi tra ve x
	//tim snt gan nhat < x
	long long primeLower = x-1;
	while (checkPrimeMillerRabin(primeLower) == false)
	{
		primeLower--;
	}
	//tim snt gan nhat > x
	long long primeUpper = x+1;
	while (checkPrimeMillerRabin(primeUpper) == false)
	{
		primeUpper++;
	}
	if ((x-primeLower) <= (primeUpper - x))
	{
		return primeLower;
	}
	else
	{
		return primeUpper;
	}
}
int main()
{
	srand(time(NULL));
	long long msv;
	long long sbd;
	long long n = 123456;
	printf("Nhap phan so cua MSV, VD: MSV la AT190157 -> nhap 190157: ");
	scanf("%lld", &msv);
	
	printf("Nhap SBD: ");
	scanf("%lld",&sbd);
	
	long long k = primeClosest(msv);
	printf("\nk = %lld\n",k);
	printf("Result = %lld",nhanBinhPhuongCoLap(sbd,k,n));
	return 0;
}
