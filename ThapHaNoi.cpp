#include <stdio.h>
ThapHaNoi(int n, char A, char B, char C){
	if (n==1){
		printf("chuyen dia 1 tu %c sang %c\n",A,C);
		
	}
	else
	{
		ThapHaNoi(n-1,A,C,B);
		printf("chuyen dia %d tu %c sang %c\n",n,A,C);
		ThapHaNoi(n-1,B,A,C);
	}
}
int main()
{
	char A = 'A',B='B',C='C';
	int n = 6;
	ThapHaNoi(n,A,B,C);
	return 0;
}
