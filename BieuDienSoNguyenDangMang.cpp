#include <stdio.h>
#include <math.h>
int main()
{
	int w = 8;
	int t = 4;
	long long a;

	printf("Nhap a: ");
	scanf("%lld",&a);
	
	int A[t]; // mang A chua t phan tu
	long long indexA[t]; // mang indexA chua cac chi so di voi tung phan tu cua A
	for (int i=t-1; i>=0; i--) //lap tu cuoi -> dau mang
	{
		indexA[i] = pow(2,i*8); //gan cac gia tri cho mang indexA
	}
	
	for (int i=t-1; i>=0; i--)
	{
		int tmp = a / indexA[i]; //gan tmp = phan nguyen cua phep chia
		A[i] = tmp; //gan tmp cho A[i]
		a = a - ( tmp * indexA[i] ); //gan lai a bang phan du sau khi chia
		
	}
	
	//in ra mang A tu cuoi len dau->chinh la bieu dien dang mang cua so 
	printf("Bieu dien dang mang cua so a la: ");
	for (int i=t-1; i>=0; i--)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
