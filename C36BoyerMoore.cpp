#include <stdio.h>
#include <string.h>

int Min(int a, int b) 
{
    return (a < b) ? a : b;
}

int main() {
    char T[1000];
    char P[1000];
    printf("\nNhap T: ");
    fgets(T, sizeof(T), stdin);
    printf("\nNhap P: ");
    fgets(P, sizeof(P), stdin);
    
	T[strcspn(T,"\n")]= '\0';
	P[strcspn(P,"\n")]= '\0';
	
    int L[127];
    int lenP = strlen(P); 
    int lenT = strlen(T);
    for (int i = 0; i < 127; i++) 
	{
        L[i] = -1;
    }
    for (int i = 0; i < lenP; i++) 
	{
        L[(int)P[i]] = i;
    }
	
	//in ra bang gia tri
	int printed[127] = {0};// mang kiem tra ki tu da in ra chua
	printf("Bang gia tri:\n");
	for (int i=0; i<lenT; i++)
	{
		if(printed[(int)T[i]] == 0)
		{
			printf("%c : %d\n", T[i], L[ (int)T[i]]);
			printed[(int)T[i]] = 1;
		}
	}
	
    int i = lenP - 1;
    int j = lenP - 1;
     
    int count = 0;
    while (i  <= lenT) 
	{
        if (P[j] == T[i]) 
        {
            if (j == 0) 
            {
                printf("P co trong T, bat dau tai vi tri %d\n", i);
                i = i + lenP;
                j = lenP - 1;
                count++;
            }
            i--;
            j--;
            
        } else 
        {
            i = i + lenP - Min(j, 1 + L[(int)T[i]]);
            j = lenP - 1;
			
        }
    }
    if (count == 0)
    {
        printf("P khong co trong T\n");
        
    }
        
   
    return 0;
}
