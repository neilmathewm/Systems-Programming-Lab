%{
#include<stdio.h>
%}
letter [a-zA-z]
number [0-9]
KEYWORD "int"|"float"|"char"|"printf"|"void"
SPC "*"|"+"|"-"|"?"|"/"|"&"|"$"|"="|"}"|"{"|";"
header "#include<".*">"
%%
{header} {printf("\n%s is Header File",yytext);}
{KEYWORD} {printf("\n%s is Keyword",yytext);}
{letter}({letter}*|{number})* {printf("\n%s is Identifier",yytext);}
"\""({letter}|{number})*"\"" {printf("\n%s is Literal",yytext);}
{number}+ {printf("\n%s is a number",yytext);}
{SPC} {printf("\n%s is Special symbol",yytext);}

%%
int main()
{
FILE *f=fopen("input.c","r");
yyin=f;
yylex();
}

