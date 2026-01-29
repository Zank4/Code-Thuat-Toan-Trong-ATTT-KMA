#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compare_pre_suff_string (int j, int i, char P[])
{
	for (int k=0; k<i; k++)
	{
		//neu co 1 ki tu khac nhau giua tien to va hau to
		if (P[k] != P[j-i+k])
			return false;
	}
	//tien to va hau to giong nhau
	return true;
}
int checkString(char P[], int j)
{
	for (int i=j-1; i>=1; i--)
	{
		//tra ve do dai i lon nhat ma tai do tien to va hau to giong nhau
		if (compare_pre_suff_string(j,i,P)==true)
			return i;
	}
	//tien to va hau to khong giong nhau tra ve 0
	return 0;
}
void failure_function(char P[], int lenP, int F[])
{
	F[0] = -1;
	F[1] = 0;
	for (int j=2; j<lenP; j++)
	{
		F[j] = checkString(P,j);
	}
}

void knutt_morris_patt(char T[], char P[], int lenT, int lenP, int F[])
{
	int i=0;
	int j=0;
	int count = 0;
	while(i <=lenT- lenP)
	{
		while (j < lenP && P[j] == T[i+j])
		{
			j++;
		}
		if (j == lenP)
		{
			count = 1;//danh dau la chuoi da xuat hien
			printf("Chuoi P xuat hien trong T tai vi tri thu %d\n",i);
			//tiep tuc so sanh tiep xem con cho nao xuat hien P nua khong
			j = 0; //gan lai j = 0 va i nhay them 1 doan = lenP
			i = i + lenP;
		}
		else
		{
			i = i + j - F[j];
			if (F[j] == -1)
			{
				j = 0;
			}
			else
			{
				j = F[j];
				
			}
		}
		
		
		
	}
	if (count == 0)
		printf("P khong xuat hien trong T");
}
int main()
{
	char T[1000];
	char P[1000];
	printf("Nhap S2: ");
	fgets(T,sizeof(T),stdin);
	printf("Nhap S1: ");
	fgets(P,sizeof(P),stdin);
	//ham xoa \n
	T[strcspn(T,"\n")] = '\0';
	P[strcspn(P,"\n")] = '\0';
	int lenT = strlen(T);
	int lenP = strlen(P);
	//tao mang F de luu gia tri failuren cua P
	int F[lenP];
	failure_function(P,lenP,F);
	//in ra gia tri cua bang failure
	printf("\nBang failure:\n");
	for (int j=0; j<lenP; j++)
	{
		printf("j = %d, F[%d] = %d\n",j,j,F[j]);
	}
	
	knutt_morris_patt(T,P,lenT,lenP,F);
	return 0;
}
