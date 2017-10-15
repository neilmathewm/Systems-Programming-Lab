#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
char line[30],def[20][20][20],sub[20][10];
int m=0,r,i,z,x=0,y=0,j,flag=0;
FILE *f1,*f2;
f1=fopen("input.c","r");
f2=fopen("output.c","w");

while(!feof(f1))
	{
	fscanf(f1,"%s",line);
	if(strcmp(line,"#define")==0)	
		{
		fscanf(f1,"%s",line);
		strcpy(def[m][0],line);	
		
		fscanf(f1,"%s",line);
		strcpy(def[m][1],line);
		m++;	
		}
	}

//for(i=0;i<m;i++)
	//printf("%s %s",def[i][0],def[i][1]);
fseek(f1, 0, SEEK_SET);
while(!feof(f1))
	{
	flag=0;
	fscanf(f1,"%s",line);
	if(strcmp(line,"#define")==0)
		{
		fprintf(f2,"%s ",line);
		fscanf(f1,"%s",line);
		fprintf(f2,"%s ",line);
		fscanf(f1,"%s",line);
		fprintf(f2,"%s ",line);	
		}
	else{
	for(i=0;i<m;i++)
		if(strcmp(line,def[i][0])==0)
			{
			fprintf(f2,"%s",def[i][1]);
		//	printf("chng:%s",def[i][1]);
			flag=1;
			break;			
			}
	if(flag==0)
		fprintf(f2,"%s ",line);
			
	   }
	}
fclose(f1);
fclose(f2);
}

