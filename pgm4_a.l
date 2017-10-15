%{
#include<stdio.h>
int k=0;
%}
A a+
B b
C cc
D cd

%%
{A}{B}({C}|{D})* {printf("corect");
	k++;
  }
.+ {printf("Invalid");}
%%
int main()
{
yyin=stdin;
yylex();
}

