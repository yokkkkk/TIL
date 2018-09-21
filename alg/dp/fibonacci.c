#include <stdio.h>

int fb(int);

int main()
{
	int f = fb(8);	
	printf("%d\n", f);
}

int fb(int n)
{
	if(n==2 || n==1)
	{
		return 1;
	}	
	else
	{
		return fb(n-1)+fb(n-2);
	}
}
