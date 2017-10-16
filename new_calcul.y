%{
#include<stdio.h>
extern int yylex();
int yyerror(char *mesg);

%}
%token NUM NL
%%
S:A NL {printf("%d",$1);}
 ;
A:A'+'B {$$=$1+$3;}
 |B {$$=$1;}
 ;
B:B'-'C {$$=$1-$3;}
 |C {$$=$1;}
 ;
C:C'*'D {$$=$1*$3;}
 |D {$$=$1;}
 ;
D:D'/'E {$$=$1/$3;}
 |E {$$=$1;}
 ;
E:NUM
 ;
%%
int yyerror(char *mesg)
{
fprintf(stderr,"%s\n",mesg);
}
int main()
{
yyparse();
}

