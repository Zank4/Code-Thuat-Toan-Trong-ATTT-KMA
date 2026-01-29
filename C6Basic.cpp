#include <stdio.h>
#include <stdbool.h>
int sumOfDiv(int x)
{
	int s = 0;
	for (int i=1; i<=x/2; i++)
	{
		if (x%i==0)
			s+=i;
	}
	
	return s;
}
bool check(int a, int b)
{
	if (a == sumOfDiv(b) && b == sumOfDiv(a))
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	scanf("%d", &n);
	int k=0;
	for (int i=1; i<n-1; i++)
	{
		for (int j = i+1; j<n; j++)
		{
			if (check(i,j)==true)
			{
				printf("Cap so: %d %d\n",i,j);
				k++;
			}
		}
	}
	if (k==0)
		printf("Khong co cap so nao");
	return 0;
}
