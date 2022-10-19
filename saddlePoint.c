#include<stdio.h>
void Add(int r,int c,int a[r][c],int b[r][c],int* ptr1,int* ptr2)
{
	
	int a3[r][c];
	int *ptr3=&a3[0][0];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
		a3[i][j]=(*(ptr1 + ((i*3)+j)))+(*(ptr2 + ((i*3)+j)));
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
		printf("%d ",*(ptr3 + ((i*3)+j)));
		}
		printf("\n");
	}
}
void Multiply(int r1,int c1,int r2,int c2,int a[r1][c1],int b[r2][c2],int* ptr1,int* ptr2)
{
	int a3[r1][c2];
	int *ptr3=&a3[0][0];
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			a3[i][j]=0;
		}
	}	
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			for(int k=0;k<r2;k++)
			{
				a3[i][j]= a3[i][j] + *(ptr1 + ((i*c2)+k))*(*(ptr2 + ((k*c2)+j)));
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
		printf("%d ",*(ptr3 + ((i*3)+j)));
		}
		printf("\n");
	}

}
void SaddlePoint(int r,int c,int a[r][c],int *ptr1)
{
	int i,j,k,min,max,s[2][2];
	int * ptr2=&s[0][0];

	for(i=0;i<r;i++)
	{
		//min = a[i][0];
		min = *(ptr1 + ((i*c) + 0));
		for(j=0;j<c;j++)
		{
			if(min>=a[i][j])
			{
				min = *(ptr1 + ((i*c) + j));
				s[0][0]=i;
				s[0][1]=j;
			}
		}
		j=s[0][1];
		max=*(ptr1 + ((0*c) + j));
		s[1][0]=0;
		s[1][1]=j;	
		for(k=0;k<r;k++)
		{
			if(max<a[k][j])
			{
				max = *(ptr1 + ((k*c) + j));
				s[1][0]=k;
				s[1][1]=j;
			}
		}
		if(min == max)
		{
		if(s[0][0]==s[1][0] && s[0][1]==s[1][1])
		{
		printf("The saddle point of matrix is : %d ",min);
		}
		}
	}
}

void main()
{
	int r1,c1;
	printf("Enter rows and columns for matrix A");
	scanf("%d %d",&r1,&c1);
	int a1[r1][c1];
	int * ptr1=&a1[0][0];
	
	printf("Enter matrix A");
	for(int p=0;p<r1;p++)
	{
		for(int q=0;q<c1;q++)
		scanf("%d",(ptr1 + ((p*c1)+q)));
	}
	int r2,c2;
	printf("Operation to be performed");
	printf("1.Addtion \n 2.Multiplication \n 3.Saddle Point \n");
	int choice;
	scanf("%d",&choice);
	if(choice == 1)
	{
	printf("Enter rows and columns for matrix B");
	scanf("%d %d",&r2,&c2);
	int a2[r2][c2];
	int * ptr2=&a2[0][0];
	printf("Enter matrix B");
	for(int p=0;p<r2;p++)
	{
		for(int q=0;q<c2;q++)
		scanf("%d",(ptr2 + ((p*c2)+q)));
	}
	Add(r1,c1,a1,a2,ptr1,ptr2);
	}
	else if(choice == 2)
	{
	printf("Enter rows and columns for matrix B");
	scanf("%d %d",&r2,&c2);
	int a2[r2][c2];
	if(r2==c1)
	{
	int * ptr2=&a2[0][0];
	printf("Enter matrix B");
	for(int p=0;p<r2;p++)
	{
		for(int q=0;q<c2;q++)
		scanf("%d",(ptr2 + ((p*c2)+q)));
	}
	Multiply(r1,c1,r2,c2,a1,a2,ptr1,ptr2);
	}
	else
	printf("Multiplication not possible");
	}
	else if(choice == 3)
	{
	SaddlePoint(r1,c1,a1,ptr1);
	}
	printf("Do you want to continue? Y or N");
	char again;
	scanf(" %c",&again);
	if(again == 'Y')
	main();
		
}
