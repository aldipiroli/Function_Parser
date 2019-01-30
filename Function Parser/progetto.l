%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
%}

%%
return 														{return RETURN;}
function													{return FUNCTION_DEF;}

[a-zA-Z][a-zA-Z0-9]*\(  									{yylval.string=strdup(yytext);return ID_FUNCTION;}

[a-zA-Z][a-zA-Z0-9]*  										{return ID_PARAMETER;}
,{1,1} 														{printf("comma");}
\) 															{printf("close parenthesis");}

\{ 															{printf("open parenthesis graffa");}
\} 															{printf("close parenthesis graffa");}

\+ 															{printf("plus");}
\* 															{printf("per");}

[0-9]+														{yylval.number=atoi(yytext);return NUMBER;}	

[0-9]+[a-zA-Z]+[a-zA-Z0-9]* 								{printf("syntax error\n");}
\n                      									{/* ignore end of line */;}
[ \t]+                  									{/* ignore whitespace */;}												
%%