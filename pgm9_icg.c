#include<stdio.h>
#include<string.h>
int prec(char a)
	{
	if(a=='^')
		return 5; 
	else if(a=='/'||a=='*')
		return 4;
 	else if(a=='+'||a=='-')
		return 3;	
	else if(a=='=')
		return -1;
	else return 0;	
	}
void main()
{
char str[100];
char temp='A';
int flag=0;//assigmn expn or not
int k=0,t,max=0,pos=0,len,j,i;
printf("\nEnter the input : ");
scanf("%s",str);
if(str[1]=='=')
	flag=1;

	len=strlen(str);
	while(len>2){
		max=0;pos=0;
		for(i=strlen(str)-1;i>0;i--)
		{
		//printf("\nchar %c-prec:%d",str[i],prec(str[i]));
		t=prec(str[i]);
		if(t>=max)
			{max=t;
			pos=i;}
		}
	//printf("max %d pos %d",max,pos);
	printf("\n%c=%c%c%c",temp,str[pos-1],str[pos],str[pos+1]);
		
	len=strlen(str);
	str[pos-1]=temp++;
	k=pos+2;	
	for(j=pos;j<len;j++)	
		str[j]=str[k++];
	//str[len-2]='\0';
	printf("\t//%s",str);
	//printf("\n%c=temp%d",str[0],k-1);
	len=strlen(str);
	if(len==3&&str[1]=='=')
		{printf("\n%s",str); break;}		
	}	
	
}
