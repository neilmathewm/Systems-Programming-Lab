%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
int yylex();
%}
%token FOR OPA STMT CONDN SEMI STEP CPA NL OB CB

%%
s:	FOR OPA STMT CONDN SEMI STEP CPA NL OB NL STMT NL CB NL	{	printf("valid");
	exit(0);	}
	;
%%
int yyerror(char *s)
{
printf("Invalid..eror");
}
void main()
{
printf("Enter Statement : ");
yyparse();
}
