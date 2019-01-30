%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}

int yywrap()
{
        return 1;
}

main()
{
        yyparse();
}

char *id_function;

%}


%union 
{
        char *string;
        int number
}


%token <string> ID_FUNCTION
%token <number> NUMBER




%token RETURN FUNCTION_DEF ID_PARAMETER

%% 

commands:
        | commands command
        ;


command:
        function_detection



function_detection:
        NUMBER
        {
                printf("\tNum '%d'\n",$1);
              /*  printf("\tNome Funzione '%s'\n",$1);
                id_function=$1;
                printf("\tSlavato: %s",id_function);*/
        }
        ;