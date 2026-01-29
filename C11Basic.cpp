#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
long long nhanBinhPhuongCoLap(long long a, long long k, long long n)
{
	long long b = 1;
	long long A = a;
	if (k%2 == 1)
	{
		b = a;
	}
	k /= 2;
	while (k>0)
	{
		A = (A*A)%n;
		if (k%2==1)
			b = (A*b) % n;
		k /= 2;
	}
	return b;
}

bool checkPrimeFermat(long long n)
{
	if (n<=1)
		return false;
	if (n==2 || n == 3)
		return true;
	if (n%2==0)
		return false;
	int t = 5;
	for (int i=1; i<=5; i++)
	{
		int a = rand()%(n-3) + 2;
		int r = nhanBinhPhuongCoLap(a,n-1,n);
		if (r != 1)
			return false;
	}
	return true;
}
int main()
{
	srand(time(NULL));
	long long n;
	scanf("%lld", &n);
	long long s = 0;
	for (long long i=1; i<=n; i++)
	{
		if(checkPrimeFermat(i) == true)
			s+=i;	
	}	
	printf("%lld", s);
	return 0;
}
