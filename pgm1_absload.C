#include <stdio.h>
#include <string.h>
int main()
{
char line[10],file[15],sub[20],start[10],length[10];
FILE *fp1,*fp2;
int i,strt,lngth;
printf("Enter File Name : ");
scanf("%s",file);
fp1=fopen("inp.dat","r");
fp2=fopen("out2.dat","w");
fscanf(fp1,"%[^\n]",line);
while(line[0]!='E')
{
//printf("%s",line);
if(line[0]=='H')
{
for(i=0;i<6;i++)
		{
		if(line[i+1]!=' ')
			sub[i] = line[i+1];
		else
			break;
		}
		sub[i] = '\0';
		if(strcmp(sub,file)!=0)
			{
			printf("\nInvalid File");
			break;
			}
	for(i=7;i<13;i++)
		start[i-7] = line[i];
	start[i-7]='\0';
	sscanf(start,"%x",&strt);
//	printf(":%x:",strt+10);
	for(i=13;i<19;i++)
		length[i-13] = line[i];
	length[i-13]='\0';
	sscanf(length,"%x",&lngth);
//	printf(":%s:",length);
}
else if(line[0]=='T')
{
i=9;
while(line[i]!='\0')
	{
	fprintf(fp2,"\n%X  %c%c",strt,line[i],line[i+1]);
	printf("\n%X  %c%c",strt++,line[i],line[i+1]);
	i=i+2;
	}
}
fscanf(fp1,"%s",line);
}
fclose(fp1);
fclose(fp2);
}
