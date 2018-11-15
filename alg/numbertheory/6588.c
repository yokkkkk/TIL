#include <stdio.h>
#include <string.h>
#include <math.h>

#pragma warning(disable:4996)

#define MAXCASE 1000000

unsigned char testCase[(MAXCASE + 7) / 8];
//if Prime, return 1
inline int isPrime(int k)
{
	return testCase[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k)
{
	testCase[k >> 3] &= ~(1 << (k & 7));
}

int main()
{
	int i = 0, j = 0;
	int T = MAXCASE; //target
	int tmp = 0;
	int findFlag = 1;

	memset(testCase, 0xff, sizeof(testCase));

	setComposite(0);
	setComposite(1);

	//setting prime
	T = sqrt(T);

	for (i = 2; i <= T; i++)
	{
		if (isPrime(i))
			for (j = i * i; j <= MAXCASE; j += i)
				setComposite(j);
	}

	while (1)
	{
		findFlag = 1;
		scanf("%d", &T);

		if (!T)
			break;
		else
		{
			tmp = T/2;
			for (i = 3; i <= tmp; i+=2)
			{
				if (isPrime(i))
					if (isPrime(T - i))
					{
						printf("%d = %d + %d\n", T, i, T - i);
						findFlag = 0;
						break;
					}
			}

			if (findFlag)
				printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
}