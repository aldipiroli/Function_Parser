%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "functionParser.h"

%}

%%
return 														{return RETURN_TOK;}
function													{return FUNCTION_TOK;}

[a-zA-Z][a-zA-Z0-9]*\(  									{yylval.string=strdup(yytext);return ID_FUNCTION;}

[a-zA-Z][a-zA-Z0-9]*  										{yylval.string=strdup(yytext);return ID_PARAMETER;}
,{1,1} 														{return COMMA_TOK;}
\) 															{return CLOSE_PAR_TOK;}

\{ 															{return OPEN_BRACES_TOK;}
\} 															{return CLOSE_BRACES_TOK;}

\+ 															{yylval.string=strdup(yytext);return PLUS_TOK;}
\* 															{yylval.string=strdup(yytext);return MULT_TOK;}

;{1,1} 														{return SEMICOLON_TOK;}

[0-9]+.[0-9]+|[0-9]+												{yylval.number=atof(yytext);return NUMBER;}	

[0-9]+[a-zA-Z]+[a-zA-Z0-9]* 								{printf("syntax error\n");}
\n                      									{/* ignore end of line */;}
[ \t]+                  									{/* ignore whitespace */;}												
%%