#include<stdio.h>
#include<string.h>
char ch[25];
int ptr=0,len,flag=0;
void E();
void E1();
void T();
void T1();
void F();

void main()
{
printf("Input String : ");
scanf("%s",ch);
len=strlen(ch);
E();
if(ptr==len&&flag==1)
	printf("\nINPUT ACCEPTED \n");
else
	printf("\nNot Accepted\n");
}
void E()
	{
	flag=0;
	T();
	if(flag==1)
	E1();		
	}
void T()
	{
	flag=0;
	F();
	if(flag==1)
	T1();
	}
void E1()
	{
	flag=0;
	if(ch[ptr]=='+')
		{
		ptr++;
		flag=1;
		T();
		if(flag==1)
		E1();		
		}
	else
		flag=1;
	}
void T1()
	{
	flag=0;
	if(ch[ptr]=='*')
		{
		flag=1;
		ptr++;
		F();
		if(flag==1)		
		T1();		
		}
	
	else
		flag=1;
	
	}
void F()
	{
	flag=0;
	if(ch[ptr]=='(')
		{
		flag=1;
		ptr++;
		E();		
		if(flag==1)		
		if(ch[ptr]==')')		
		ptr++;		
		}
	else if(ch[ptr]=='i'&&ch[ptr+1]=='d')
		{
		flag=1;
		ptr+=2;		
		}	
	}
