#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
long long nhanBinhPhuongCoLap(long long a, long long k, long long n) // a^k mod n
{
	long long b = 1;
	long long A = a;
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
			b = (A*b) % n;
		}
		k /= 2;
	}
	return b;
}

bool checkPrimeFermat(long long n)
{
	if (n<=1)
		return false;
	if (n==2 || n==3)
		return true;
	if (n%2==0)
		return false;
	int t = 5;
	
	for (int i=1; i<=t; i++)
	{
		long long a = rand()%(n-3) + 2;
		long long r = nhanBinhPhuongCoLap(a,n-1,n);
		if (r!=1)
			return false;
	}
	return true;
}
int main()
{
	srand(time(NULL));
	long long a,b;
	printf("Nhap a: "); scanf("%lld", &a);
	printf("Nhap b: "); scanf("%lld", &b);
	if (a>=b)
	{
		printf("Nhap lai (a<b)");
		return 0;
	}
	long long d = sqrt(b) +1; //vi mang bat dau tu chi so 0 nen cong them 1 
	long long s1[d], s2[d];
	//luu cac gia tri binh phuong tu 0 den sqrt(b) vao s1[] s2[]
	for (long long i=0; i<d; i++)
	{
		s1[i] = i*i;
		s2[i] = i*i;
	}
	int count = 0;
	for (long long n=a; n<=b; n++)
	{
		if (checkPrimeFermat(n) == true)
		{
			bool check = false; //moi lan lap n se tao bien check = false
			//kiem tra xem co la tong cua 2 so trong s1 s2 khong
			for (long long i=0; i<d && s1[i] < b; i++)
			{
				for (long long j=0; j<d && s2[j] < b; j++)
				{
					if(s1[i] + s2[j] == n )
					{
						check = true; //khi da tim duoc thi doi check thanh true
						printf("snt thoa man: %d = %d + %d\n",n,s1[i],s2[j]);
						break; //break khoi vong lap j
					}
				}
				if (check == true)
					break; //break khoi vong lap i
			}
			
			if(check == true)	
				count++;
		}
	}
	printf("\n=> So so nguyen to phu hop dieu kien la %d",count);
	
	
	return 0;
}
