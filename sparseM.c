#include<stdio.h>
 void main()
{
	int r,c,count=0,k=0;
	printf("Enter rows and colmns");
	scanf("%d" ,&r);
	scanf("%d" ,&c);
	int a[r][c];
	printf("enter matrix:");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
		scanf("%d",&a[i][j]);
		if(a[i][j]==0)
		count++;
		else
		k++;
		}
	}
	/*if(count>(r*c)/2)
	printf("Sparse Matrix");
	else
	printf("Not a Sparse Matrix");*/
	int s[k][3],p=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
			s[p][0]=i;
			s[p][1]=j;
			s[p][2]=a[i][j];
			p++;
			}
		}
	}
	printf("\tR\tC\tV\n");
	for(int i=0;i<k;i++)
	{
		printf("\t%d\t%d\t%d",s[i][0],s[i][1],s[i][2]);
		printf("\n");
	}
		
	
}
