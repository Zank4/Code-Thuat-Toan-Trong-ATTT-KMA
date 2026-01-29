#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int nhanBinhPhuongCoLap(int a, int k, int n)
{
	int b = 1;
	int A = a;
	if (k%2==1)
	{
		b = a;
	}
	k /= 2;
	while (k>0)
	{
		A = (A*A) % n;
		if (k%2==1)
		{
			b = (A*b)%n;
		}
		k /= 2;
	}
	return b;
}

bool checkPrimeFermat(int n)
{
	if (n<=1)
		return false;
	if (n==2 || n==3)
		return true;
	if(n%2==0 || n%3 ==0)
		return false;
	int t=5;
	for (int i=0; i<t; i++)
	{
		int a = rand() % (n-3) + 2;
		int r = nhanBinhPhuongCoLap(a,n-1,n);
		if (r!=1)
			return false;
	}
	return true;
}

int main()
{
	srand(time(NULL));
	int n,m;
	printf("Nhap N: "); scanf("%d",&n);
	printf("Nhap M: "); scanf("%d",&m);
	if (n<1 || n>10000 || m<=2 || m>100)
	{
		printf("Nhap lai 1<= N <=10000; 2< M <=100");
		return 0;
	}
	
	//tim cac snt <=n va luu vao 1 mang
	int a[n];
	int index = 0;
	for (int i=2; i<=n; i++)
	{
		if(checkPrimeFermat(i) == true)
		{
			a[index] = i;
			index++;
		}
	}
	//xac dinh xem n phan tich duoc thanh tong cua m snt khong
	//ERROR: code nay chi kiem tra duoc n co la tong cua m snt lien ke nhau hay khong, chua dung voi yeu cau bai toan
	int M = m;
	int s=0;
	for (int i=0; i<=index-M; i++)
	{
		for (int j=i; j<m; j++)
		{
			s += a[j];
		}
		if (s == n)
		{
			for (int k=i; k<m; k++)
			{
				printf("%d ",a[k]);
			}
			break;
		}
		s=0;
		m++;
	}
	return 0;
}

