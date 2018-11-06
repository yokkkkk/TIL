#include <stdio.h>

#define MAX(x, y) x>=y?x:y

int upstaris(int *score, int n)
{
	int i = 0 , step = 0;
	int q = 0;
	int didContinue=0;
	int _case[4];
	int prevCase = -1;
	int *stage = (int*)malloc(sizeof(int)*(n+1));
	stage[0] = 0;
	//max stage[N] = stage[N] + stage[N-1] + stage[N-3]
	//             or
	//               stage[N] + stage[N-2] + stage[N-3]
	//               stage[N] + stage[N-2] + stage[N-4]
	//if N<=0: END
	//max(N-3) or max(N-4)
	for (i = 0; i <= n; i += 4)
	{
		_case[0] = score[i] + score[i + 2] + score[i + 3]; //1,2,1
		_case[1] = score[i] + score[i + 1] + score[i + 3]; //1,1,2
		_case[2] = score[i] + score[i + 2] + score[i + 3]; //2,1,1
		_case[3] = score[i] + score[i + 2] + score[i + 3]; //2,1,2

		if (prevCase != 2)
		{
			if (prevCase == 0) //0,2,3
			{
				if (_case[0] > _case[2])
				{
					_case[]
				}
				stage[i / 4] = max(max(_case[0], _case[2]), _case[3]);
			}
			else//all
			{
				stage[i / 4] = max(max(max(_case[0], _case[2]), _case[3]), _case[1]);
			}
		}
		else//2,3
		{
			stage[i / 4] = max(_case[2], _case[3]);
		}
	}
	
	for (i = 0; i <= n; i += 4)
	{
		q += stage[i / 4];
	}
	return q;
}

int main()
{
	int s[] = { 10,20,15,25 };
	printf("%d\n", upstaris(s, sizeof(s)/sizeof(int)));
	getchar();

}