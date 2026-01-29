#include <stdio.h>
#include <math.h>

// Tìm bac cua da thuc o dang co so 10
int bac(int x)
{
    int count = 0;
    while(x != 0)
    {
        x /= 2;
        count++;
    }
    return count - 1;
}

// Chia lay du da thuc trong GF(2)
int chiaLayDuDaThucGF2(int result10, int g)
{
    int bac_result = bac(result10);
    int bac_g = bac(g);
    
    while (bac_result >= bac_g) 
    {
        int z = bac_result - bac_g;
        result10 ^= g << z;
        bac_result = bac(result10);
    }
    
    return result10;
}

// Chia lay nguyên da thuc trong GF(2)
int chiaLayNguyenDaThucGF2(int result10, int g)
{
    int bac_result = bac(result10);
    int bac_g = bac(g);
    
    int kq[17] = {0};  
    while (bac_result >= bac_g) 
    {
        int z = bac_result - bac_g;
        kq[z] = 1; // Gán vào mang o vi trí thu z là do chênh lech bac giua 2 da thuc
        result10 ^= g << z;
        bac_result = bac(result10);
    }
    
    // Chuyen da thuc kq[] sang co so 10
    int ketQua = 0;
    for (int i = 0; i < 17; i++)
    {
        ketQua += kq[i] * pow(2, i);
    }
    return ketQua;
}

// Nhân hai da thuc trong GF(2) và chia lay du voi da thuc g
int multiply(int a, int b, int g)
{
    int A[9] = {0}; 
    int B[9] = {0};
    int indexA = 0;
    int indexB = 0;
    while(a > 0)
    {
        A[indexA] = a % 2;
        a /= 2;
        indexA++;
    }
    while(b > 0)
    {
        B[indexB] = b % 2;
        b /= 2;
        indexB++;
    }
    int result[17] = {0}; // Do 2 da thuc bac 2 nhân voi nhau se mu max = 4, tao mang có 5 phan tu luu các chi so
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            result[i + j] ^= (A[i] * B[j]); // VD x^i * x^j = x^(i + j), luu vào vi trí so mu thu i + j tuong ung
        }
    }
    // Ðoi mang chi so result sang he co so 10
    int result10 = 0;
    for (int i = 0; i <= 16; i++)
    {
        result10 += result[i] * pow(2, i);
    }
    
    // Mod voi da thuc g
    int result_du = chiaLayDuDaThucGF2(result10, g);
    return result_du;
}

// Tìm nghich dao modulo cua da thuc trong GF(2)
int inverse_modul_DaThucGF2(int a, int g)
{
    int u = a;
    int v = g;
    int x1 = 1;
    int x2 = 0;
    int q, r, x;
    while (u != 1)
    {
        q = chiaLayNguyenDaThucGF2(v, u); // Chia lay nguyên cua v cho u
        r = chiaLayDuDaThucGF2(v, u); // Chia lay du cua v cho u
        x = x2 ^ multiply(q, x1, g); // x2 - q * x1 (dùng phép XOR)
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    return x1;
}

int main()
{
    int Ax[9];
    printf("Nhap da thuc a:\n");
    
    for (int i = 8; i >= 0; i--)
    {
        printf("\n\tNhap he so di voi x^%d: ", i);
        scanf("%d", &Ax[i]); // Lúc này mang a dang luu chi so ví du x^2 + x + 1 se luu là 111
    }

    // Bien mang A dang luu các chi so nhi phân sang he co so 10 VD: nhi phân 0111 -> 7
    int a = 0;
    for (int i = 0; i <= 8; i++)
    {
        a += Ax[i] * pow(2, i);
    }

    int G[9];
    printf("\nNhap da thuc g:\n");
    
    for (int i = 8; i >= 0; i--)
    {
        printf("\n\tNhap he so di voi x^%d: ", i);
        scanf("%d", &G[i]);
    }
    // Bien mang G sang he co so 10
    int g = 0;
    for (int i = 0; i <= 8; i++)
    {
        g += G[i] * pow(2, i);
    }

    int kq = inverse_modul_DaThucGF2(a, g);
    
    int ketQua[9] = {0};
    int count = 0;
    while (kq>0)
    {
    	ketQua[count] = kq%2;
    	kq/=2;
    	count++;
	}
	
	for (int i=8; i>=0; i--)
	{
		if (ketQua[i] == 1)
		{
			printf("x^%d +",i);
		}
	}
    return 0;
}

