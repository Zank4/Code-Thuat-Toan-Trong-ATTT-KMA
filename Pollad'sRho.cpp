#include <stdio.h>
long long gcd(long long a,long long b)
{
    long long A = a, B = b;
    long long R;
    while (B>0)
    {
        R = A%B;
        A = B;
        B = R;
    }
    return A;
}
int main()
{
    printf("Nhap hop so n va n khong phai la luy thua cua 1 so nguyen to\n");
    long long n;
    scanf("%lld",&n);
   long long a =2, b=2;
    long long d;
    int c = 1;
    while(1)
    {
    	
        a = (a*a +c)%n;
        b = (b*b +c)%n;
        b = (b*b +c)%n;
        long long t = a - b;
        d = gcd(t,n);

        if(1<d && d<n)
        {
            printf("%lld",d);
            break;
        }
        if (d == n)
        {
        	c++;
        	continue;
		}
    }
    
return 0;
}
