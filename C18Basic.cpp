#include <stdio.h>
#include <math.h>
void BieuDienSoNguyenDangMang(long long a, long long b, int w, int t, long long A[], long long B[])
{
	//bien doi so nguyen a sang mang va gan vao mang A[]
	long long indexA[t]; // mang indexA chua cac chi so di voi tung phan tu cua A
	for (int i=t-1; i>=0; i--) //lap tu cuoi -> dau mang
	{
		indexA[i] = pow(2,i*8); //gan cac gia tri cho mang indexA
	}
	
	for (int i=t-1; i>=0; i--)
	{
		long long tmp = a / indexA[i]; //gan tmp = phan nguyen cua phep chia
		A[i] = tmp; //gan tmp cho A[i]
		a = a - ( tmp * indexA[i] ); //gan lai a bang phan du sau khi chia
		
	}
	//bien doi so nguyen b sang mang va gan vao mang B[]
	long long indexB[t]; // mang indexB chua cac chi so di voi tung phan tu cua B
	for (int i=t-1; i>=0; i--) //lap tu cuoi -> dau mang
	{
		indexB[i] = pow(2,i*8); //gan cac gia tri cho mang indexB
	}
	
	for (int i=t-1; i>=0; i--)
	{
		long long tmp = b / indexB[i]; //gan tmp = phan nguyen cua phep chia
		B[i] = tmp; //gan tmp cho B[i]
		b = b - ( tmp * indexB[i] ); //gan lai b bang phan du sau khi chia
		
	}
}

long long BieuDienMangDangSoNguyen(long long C[],int w, int t)
{
	long long c = 0;
	for (int i=t-1; i>=0; i--)
	{
		c += pow(2,i*w) * C[i];
	}
	return c;
}
int main()
{
	int w = 8;
	int t = 4;
	int key;
	long long a,b;
	long long A[t];
	long long B[t];
	printf("Chon:\n	1. Nhap a,b dang so nguyen\n	2. Nhap a,b dang mang(array)\n\n");
	scanf("%d",&key);
	switch(key)
	{
		case(1):
			printf("Nhap a: ");
			scanf("%lld", &a);
			printf("Nhap b: ");
			scanf("%lld", &b);
			
			//bien doi a va b sang dang mang
			BieuDienSoNguyenDangMang(a,b,w,t,A,B);
		
			break;
		case(2):
			printf("Nhap a(dang mang array): \n");
			for (int i=t-1; i>=0; i--) //nhap va luu tu cuoi mang len dau mang **thuat toan culol no lai the co
			{
				scanf("%lld",&A[i]);
			}
			
			printf("Nhap b(dang mang array): \n");
			for (int i=t-1; i>=0; i--) //nhap va luu tu cuoi mang len dau mang **thuat toan culol no lai the co
			{
				scanf("%lld",&B[i]);
			}
			
			break;
	}
	
	//bat dau lam thuat toan cong a voi b, luu y a va b da chuyen qua dang mang
	long long C[t];
	int e = 0;
	for (int i=0; i<t; i++ )
	{
		long long tmp = A[i] + B[i] + e;
		long long n = pow(2,w);
		if(tmp > n)
		{
			e = 1;
		}
		else
		{
			e = 0;
		}
		C[i] = tmp%n;
	}
	
	printf("\n\nKet Qua:\n");
	printf("\t\t e = %d\n",e);
	printf("\t\t Tong a+b dang mang: ");
	for (int i=t-1; i>=0; i--)
	{
		printf("%lld ",C[i]);
	}
	printf("\n\t\t Tong a+b dang so nguyen: ");
	printf("%lld",BieuDienMangDangSoNguyen(C,w,t));
	
	return 0;
}
