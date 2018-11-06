#include <stdio.h>

#pragma warning(disable:4996)

#define MIN_2(x, y) (x > y? y : x)
#define MINHousePrice(h) (MIN_2(MIN_2(h[1], h[2]), h[3]))

int ColorPerHouse[1001][3] = { '\0' };
int dp[1001][4] = { '\0' };

int main()
{
	int i = 0, j = 0;
	int N = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) // input color price
		for (j = 0; j <3; j++)
			scanf("%d", &ColorPerHouse[i][j]);

	dp[1][1] = ColorPerHouse[1][0]; //R
	dp[1][2] = ColorPerHouse[1][1]; //G
	dp[1][3] = ColorPerHouse[1][2]; //B

	for (i = 2; i <= N; i++)
	{
		dp[i][1] = MIN_2(dp[i - 1][2], dp[i - 1][3]) + ColorPerHouse[i][0];
		dp[i][2] = MIN_2(dp[i - 1][1], dp[i - 1][3]) + ColorPerHouse[i][1];
		dp[i][3] = MIN_2(dp[i - 1][1], dp[i - 1][2]) + ColorPerHouse[i][2];
	}
	printf("%d\n", MINHousePrice(dp[N]));
}

/*
dp = (int**)malloc(sizeof(int*)*(N + 1));

for (j = 1; j <= N; j++)
dp[j] = (int*)malloc(sizeof(int) * 3);
*/
