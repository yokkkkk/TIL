#include <stdio.h>

#pragma warning(disable:4996)

int main()
{
	int i = 0, j = 0;
	int T = 0;
	int tmp = 0;
	int *dp = NULL;
	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		scanf("%d", &tmp);

		dp = (int*)malloc(sizeof(int) * (tmp + 1));
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (j = 4; j <= tmp; j++)
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]);
		printf("%d\n", dp[tmp]);
	}
}