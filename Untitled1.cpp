#include <stdio.h>
#include <math.h>
void BieuDienSoNguyenDangMang(long long a, int w, int t, int A[])
{
	//bien doi so nguyen a sang mang va gan vao mang A[]
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

}

long long BieuDienMangDangSoNguyen(int C[],int w, int t)
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
	int A[t];
	int B[t];
	
			printf("Nhap a: ");
			scanf("%lld", &a);
			printf("Nhap b: ");
			scanf("%lld", &b);
			
			//bien doi a va b sang dang mang
			BieuDienSoNguyenDangMang(a,w,t,A);
			BieuDienSoNguyenDangMang(b,w,t,B);
		
	// a va b da chuyen qua dang mang
	int C[t];
	int e = 0;
	for (int i=0; i<t; i++)
	{
		int tmp = A[i] + B[i] + e;
		int n = pow(2,w);
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
		printf("%d ",C[i]);
	}
	printf("\n\t\t Tong a+b dang so nguyen: ");
	printf("%lld",BieuDienMangDangSoNguyen(C,w,t));
	
	return 0;
}
