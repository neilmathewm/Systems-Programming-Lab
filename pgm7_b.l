%{
#include "y.tab.h"
#include<stdio.h>
%}
dig [0-9]
nl "\n"
%%
{dig}+ {yylval=atoi(yytext);
	return DIGIT;}
[+]|[-]|[*]|[/] {return *yytext;}
"("|")" {return *yytext;}
{nl} {return NL;}
