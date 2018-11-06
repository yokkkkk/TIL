#include <stdio.h>

#pragma warning(disable:4996)

#define MAX_2(x, y) (x > y? x : y)
#define MAX_3(x, y, z) (MAX_2(x, y), z)

long long int amount[10001];
long long int dp[10001][3];

int main()
{
	int N = 0;
	int i = 0, j = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &amount[i]);

	dp[1][0] = amount[1];
	dp[2][1] = amount[2] + amount[1]; // if set 1, step on the prev stairs
	dp[2][0] = amount[2];

	for (i = 3; i <= N; i++)
	{
		dp[i][0] = MAX_3(dp[i - 2][0], dp[i - 2][1], dp[i-2][2]) + amount[i];
		dp[i][1] = amount[i] + amount[i - 1] + MAX_3(dp[i - 3][0], dp[i - 3][1], dp[i - 3][2]);
		dp[i][2] = amount[i] + MAX_3(dp[i - 2][0], dp[i - 2][1], dp[i - 2][2]);
	}

		

	printf("%lld\n", MAX_3(MAX_3(dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]), MAX(dp[N][0], dp[N][1], dp[N][2]), MAX(dp[N - 2][0], dp[N - 2][1], dp[N - 2][2])));
	getchar();

	getchar();
	getchar();
	return 0;
}
