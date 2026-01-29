#include <stdio.h>
#include <math.h>

int main()
{
	int t=4;
	int w =8;
	long long a = 0;
	int A[t];
	//nhap mang bieu dien so nguyen do va gan tu cuoi len dau, o vidu nay ta nhap (0,11,173,248) -> 765432
	for (int i=t-1; i>=0; i--)
	{
		scanf("%d", &A[i]);
	}
	//tinh toan ra so nguyen tu mang da nhap
	for (int i=t-1; i>=0; i--)
	{
		a += pow(2,i*w) * A[i];
	}
	printf("Bien dien so nguyen cua mang la: %lld",a);
}
