%{
#include "y.tab.h"
#include<stdio.h>
typedef int YYSTYPE;
YYSTYPE  yylval;
%}

dig [0-9]
nl "\n"
%%
{dig}+ {yylval=atoi(yytext);
	return NUM;}
[+]|[-]|[*]|[/] {return *yytext;}
{nl} {return NL;}
%%
