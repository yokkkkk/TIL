#include <stdio.h>

#pragma warning(disable:4996)

int fibo[41][2];
int num[40];

/* example source code in dp_1003*/

int main()
{
	int i = 0, j = 0;
	int T = 0;
	
	scanf("%d", &T);

	for (i = 1; i <= T; i++) // TastCase num[0], num[1]..
		scanf("%d", &num[i - 1]);

	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;


	for (i = 1; i <= T; i++) //loop for testcase
	{
		for (j = 2; j <= 40; j++)
		{
			fibo[j][0] = fibo[j - 1][0] + fibo[j - 2][0];
			fibo[j][1] = fibo[j - 1][1] + fibo[j - 2][1];
		}
		printf("%d %d\n", fibo[num[i - 1]][0], fibo[num[i - 1]][1]);
	}
}