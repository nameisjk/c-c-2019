#include<stdio.h>
int main()
{
	int n,x=0,y=0,z=1;
	printf("/*************************\n斐波那契数列\n前面相邻俩项之和构成后一项\n");
	printf("input a number\n");
	scanf("%d",&n);

	for(n;n>0;n--)
	{
		printf("%5d",z);
		x=y;y=z;z=x+y;
	}

	return 0;
}
