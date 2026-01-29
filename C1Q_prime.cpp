#include <stdio.h>
#include <stdbool.h>
bool IsQprime(long long a)
{
	if (a <= 1) //so 0 co vo so uoc va so 1 chi co duy nhat 1 uoc nen loai luon
		return false;
	int count = 2; // 1 so luon co it nhat 2 uoc la 1 va chinh no
	for (long long i=2; i<=a/2; i++) //cac uoc cua 1 so a ngoai tru chinh no thi luon <= a/2, giam thieu buoc lap
	{
		if (a%i == 0)
		{
			count++;
		}
	}
	if (count == 4)
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
	scanf("%lld", &n);
	int k=0;
	for (long long i=0; i<=n; i++) 
	{
		if(IsQprime(i) == true)
		{
			printf("%d\n",i);
			k++;
		}
	}
	if (k == 0)
		printf("khong co so nao");
	
	return 0;
}
