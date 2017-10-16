#include<stdio.h>
#include<ctype.h>
#include<string.h>

char NT[100] = {'E','F','G','H','I'};
char T[100] = {'a','+','*','(',')','$'};

char stack[100] = {"$E"};

char table[5][6][100]={{"GF"," "," ","GF"," "," "},
		       {" ","+GF"," "," ","e","e"},
		       {"IH"," "," ","IH"," "," "},
		       {" ","e","*IH"," ","e","e"},
		       {"a"," "," ","(E)"," "," "}};

int NTsearch(char ch){
	int i;
	for(i=0;i<5;i++){
		if(NT[i] == ch){
			return i;
		}
	}
	return -1;
}

int Tsearch(char ch){
	int i;
	for(i=0;i<6;i++){
		if(T[i] == ch){
			return i;
		}
	}
	return -1;
}

void main(){
	int i,j,flag =0,k,l;
	char input[100],temp[100];
	printf("Parsing table\n");
	for(i=0;i<5;i++){
		for(j=0;j<6;j++){
			printf("%s\t",table[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the input string: ");
	scanf("%s",input);
	i = strlen(input);
	input[i] = '$';
	input[i+1] = '\0';
	
	i=1;
	j=0;
	while(stack[i]!='$'){
		if(stack[i]!=input[j]){
			strcpy(temp,table[NTsearch(stack[i])][Tsearch(input[j])]);
			if(temp[0] == ' '){
				flag = 1;
				printf("\nThe input string is not accepted");
				break;
			}else if(temp[0]!='e'){
				i--;
				for(k=strlen(temp)-1;k>=0;k--){
					stack[++i] = temp[k];		
				}
				stack[i+1] = '\0';
				//printf("The stack in loop is %s\n",stack);
			}else if(temp[0] == 'e'){
				stack[i] = '\0';
				i--;
			}
		}else{
			stack[i] = '\0';
			i--;
			j++;
		}
		
		printf("stack is %s\n", stack);	
		printf("Current input charector is %c\n",input[j]);
		printf("Current stack charector is %c\n",stack[i]);
	
	}
	if(flag == 0 && stack[i] == '$'){
		printf("\nThe input is accepted\n\n");
	}
}
