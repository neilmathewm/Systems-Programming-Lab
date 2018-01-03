/* Input : Expression Tree 
   Output : Assembly Code
   By Neil M
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct tree
{
int label;
char value;
}node[40];

int registerstack[5],r,top,top_temp=3;
char temporarystack[]={'D','C','B','A'}; //for case 4

void swap_stack_top()  //function to swap top 2 elements in register stack
{
int temp;
temp=registerstack[top];
registerstack[top]=registerstack[top-1];
registerstack[top-1]=temp;
}

void gencode(int pos) 
{
int R;
char n1,n2,name,op,optr[5],T;
if(node[pos].label==1&&isalpha(node[pos].value))  //case 0     -  leaf nodes are alphabets
	printf("\nMOV %c , R%d",node[pos].value,registerstack[top]);
else if(!isalpha(node[pos].value)) //check if it is interior node  (not alphabets)
	{
	op=node[pos].value;
	n1=2*pos+1;   //left child
	n2=2*pos+2;   //right child
	if(op=='+')
			strcpy(optr,"ADD");
	else if(op=='-')
	 		strcpy(optr,"SUB");
	else if(op=='*')
			strcpy(optr,"MUL");
	if(node[n2].label==0) //case 1
		{
		name=node[n2].value;
		gencode(n1);
		printf ("\n%s %c , R%d  ",optr,name,registerstack[top]);
							
		}
	else if(node[n1].label<node[n2].label && node[n2].label<=(top+1) )//case 2
		{
		swap_stack_top();
		gencode(n2);
		R=registerstack[top--];//pop
		gencode(n1);
		printf("\n%s R%d , R%d",optr,R,registerstack[top]);
		registerstack[++top]=R;//push
		swap_stack_top();		
		}
	else if(node[n1].label>=node[n2].label && node[n1].label<=(top+1))//case 3
		{
		gencode(n1);
		R=registerstack[top--];//pop
		gencode(n2);
		printf("\n%s R%d , R%d",optr,registerstack[top],R);
		registerstack[++top]=R;
		}	
	else //case 4 both labels>r when register are less
		{
		gencode(n2);
		T=temporarystack[top_temp--];
		printf("\nMOV R%d , %c",registerstack[top],T);
		gencode(n2);
		temporarystack[++top_temp]=T;
		printf("\n%s %c , R%d  ",optr,T,registerstack[top]);
		}	
	}

}

void main()
{
int pos=0,i,j,l,n=0;
FILE *fp=fopen("exptree.txt","r");
fscanf(fp,"%d",&l);
while(!feof(fp)){
		fscanf(fp," %c %d",&node[n].value,&node[n].label);  //INSERTING INTO TREE
		n++;				
	}
printf("\nTREE\n");
r=node[0].label;//no of registers
top=r-1;
n=top;
for(i=0;i<r;i++)
	registerstack[i]=n--;
for(i=0,n=0;i<l;i++){ 
	printf("\n");
	for(j=0;j<pow(2,i);j++){    //PRINTING TREE ACCORDING TO EACH LEVEL
		printf("%c:%d:\t",node[n].value,node[n].label);
		n++;		
		}
}
printf("\n\nASSEMBLY CODE \n\n");
gencode(0);
}

