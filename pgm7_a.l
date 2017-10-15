%{
#include<stdio.h>
#include "y.tab.h"
%}

id [a-z]
digit [0-9]
relop [<]|[>]
asop "="
opa "("
cpa ")"
ob "{"
cb "}"
nl "\n"
semi ";"
step {id}+("++"|"--")
condn {id}+{relop}({id}+|{digit}+)
stmt {id}+{asop}({id}+|{digit}+)";"

%%
for {return FOR;}
{opa} {return OPA;}
{condn} {return CONDN;}
{cpa} {return CPA;}
{semi} {return SEMI;}
{nl} {return NL;}
{ob} {return OB;}
{cb} {return CB;}
{stmt} {return STMT;}
{step} {return STEP;}
%%
