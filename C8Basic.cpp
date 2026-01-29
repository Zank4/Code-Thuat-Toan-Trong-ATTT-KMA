#include <stdio.h>
#include <stdbool.h>
bool IsTprime(long long a)
{
	if (a <= 1)
		return false;
	int count = 2; //1 so nguyen luon co 2 uoc la 1 va chinh no
	for (long long i=2; i<=a/2; i++)
	{
		if (a%i == 0)
		{
			count++;
		}
	}
	if (count == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main() 
{
	long long n;
	scanf("%d", &n);
	int k=0;
	for (long long i=1; i<=n; i++)
	{
		if(IsTprime(i) == true)
		{
			printf("%lld\n",i);
			k++;
		}
	}
	if (k == 0)
		printf("No");
	
	return 0;
}
