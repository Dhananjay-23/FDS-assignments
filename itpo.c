#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
struct abc
{
    char data;
    struct abc *next;
};
struct abc *top=NULL;
void push(char d)
{
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    new->data=d;
    new->next=NULL;
    if(top==NULL)
{
    top=new;
    }
    else
    {
    new->next=top;
    top=new;
    }
}
int precedence(char d)
{
    if(d=='^')
    return 3;
    else if(d == '*' || d == '/')
    return 2;
    else if(d=='+' || d=='-')
    return 1;
}
char pop()
{
    struct abc *temp;
    char ch;
    if(top==NULL)
    {
    printf("Underflow");
    }
    else if(top->next==NULL)
    {
    temp=top;
    ch=temp->data;
    top=NULL;
    free(temp);
    }
    else
    {
    temp=top;
    ch=temp->data;
    top=top->next;
    free(temp);
    }
    return ch;
}
int stack[20],top1=-1;
void push1(int num)
{
	if(top1>19)
	{
		printf("Overflow");
	}
	else
	{
		top1++;
		stack[top1]=num;
	}
}
int pop1()
{
	int n;
	if(top1==-1)
	{
		printf("Underflow");
	}
	else
	{
		n=stack[top1];
		top1--;
	}
	return n;
}
void evaluate(char postfix[20])
{
	int i=0,num,n1,n2,n3;
    while(postfix[i]!='\0')	
    {
	if(isdigit(postfix[i]))
	{
	num=postfix[i]-48;
	push1(num);
	}
	else
	{
	n1=pop1();
	n2=pop1();
	switch(postfix[i])
	{
	case '^': n3=pow(n2,n1);
	push1(n3);
	break;
	case '*': n3=n2*n1;
	push1(n3);
	break;
	case '/': n3=n2/n1;
	push1(n3);
		break;
	case '+': n3=n2+n1;
	push1(n3);
		break;
	case '-': n3=n2-n1;
	push1(n3);
		break;
	default : printf("Incorrect expression");
	break;
	}
	}
	i++;
    }
	printf("expression value is : %d \n",n3);	
}
int main()
{
    char infix[20],postfix[20];
    printf("Enter infix expression");
    scanf("%s",infix);
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else
        {
            if(top==NULL)
            {
                push(infix[i]);
            }
            else
            {
                while(top!=NULL && precedence(top->data)>=precedence(infix[i]))
                {
                    postfix[j]=pop();
                    j++;
                }
                push(infix[i]);
            }
        }
        i++;
    }
    while(top!=NULL)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("The postfix expression is : " );
    printf("%s \n",postfix);
	evaluate(postfix);
    return 0;
}
