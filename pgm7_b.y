%{#include "y.tab.h"
%}
%token DIGIT NL
%%
L: A NL {printf("%d",$1);}
   ;
A: A'+'B{ $$=$1+$3;}
   |
   B{$$=$1;}
   ;
B: B'-'C{ $$=$1-$3;}
   |
   C{$$=$1;}
   ;
C: C'*'D{ $$=$1*$3;}
   |
   D{$$=$1;}
   ;
D: D'/'E{ $$=$1/$3;}
   |
   E{$$=$1;}
   ;
E: '('A')'{ $$=$2;}
   |
   DIGIT
   ;
%%
void main()
{
yyparse();
}
