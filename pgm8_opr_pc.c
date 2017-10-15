#include<stdio.h>
#include<string.h>
int prec[4][4]={
		{0,1,1,1},   //id
		{-1,1,-1,1}, //+
		{-1,1,1,1},  //*
 		{-1,-1,-1,2} //$
	     };
int len;
int check(char a)
{
if(a=='a')
	return 0;
else if(a=='+')
	return 1;
else if(a=='*')
	return 2;
else if(a=='$')
	return 3;

}
int validate(char a)
{
if(a=='a')
	return 1;
else if(a=='+'||a=='*'||a=='$')
    return 2;
else return 0;

}
void append(char *str,char ch,int j,int len)
{
int k;
for(k=len-1;k>=j;k--)
	str[k+1]=str[k];
str[j]=ch;
str[len+1]='\0';
}
void append_symbol(char *str)
{
int i;
for(i=0;i<len-1;i++)
	{
	if(prec[check(str[i])][check(str[i+1])]==1)
		{ append(str,'>',i+1,len);
			i++;
			len++;
		}
	else if(prec[check(str[i])][check(str[i+1])]==-1)
		{append(str,'<',i+1,len);
		i++;
		len++;
		}
	printf("\nString : %s",str);
	}
}

void main()
{

int i,j,flag;
char str[25];
printf("\nPRECEDENCE TABLE\n\n");
for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++)
		printf("%d\t",prec[i][j]);
	}
printf("\nENTER THE INPUT : ");
scanf(" %s",str);
printf("\nINPUT : %s ",str);

len=strlen(str);
flag=0;
for(i=0;i<len-1;i++)
    if(validate(str[i])&&validate(str[i+1])&&validate(str[i])!=validate(str[i+1]))
        {

        }
    else flag=1;

if(flag==0){

for(i=len;i>0;i--)
	str[i]=str[i-1];
str[0]='$';
str[len+1]='$';
str[len+2]='\0';

len=strlen(str);
printf("\nDollar Appended : %s ",str);

for(i=0;i<len;i++)
	if(str[i]=='a')
		str[i]='E';
printf("\nString : %s",str);
for(i=0;i<len;i++)
	{
	if(str[i]=='E')
		{
		for(j=i;j<len;j++)
			str[j]=str[j+1];
		len--;
		i=0;
		}
	}
printf("\nString : %s",str);
while(1){

append_symbol(str); //insert < and >
printf("\nString : %s",str);
    for(i=0;i<len-2;i++)
        {
        if(str[i]=='<'&&str[i+2]=='>')
            {for(j=i;j<len-3;j++)
                str[j]=str[j+3];
            str[j]='\0';
            len=len-3;
            }
        }
    if(str[0]=='$'&&str[1]=='$')
    {
    printf("\nString : %s",str);
      printf("\nInput Accepted");
        break;
    }
    }
}
else
    printf("\nInput Invalid");

}

