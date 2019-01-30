%{
#include <stdio.h>
#include <string.h>
#include "functionParser.c"
#define NFUNCTIONS 10 // Maximum number of functions you can define

/*Variables For The Functions Definitions*/
function_definition functions[NFUNCTIONS];
function_definition emptyStruct;
int i_function = 0;
int i_par_def = 0;
int i_par_call = 0;
int i_op = 0;

/*Variables For The Functions Calls*/
float passed_parameters[100];
int i_passed_parameters = 0;
float call_result;

%}

%union 
{
    char *string;
    float number
}

%token RETURN_TOK FUNCTION_TOK  COMMA_TOK CLOSE_PAR_TOK OPEN_BRACES_TOK CLOSE_BRACES_TOK SEMICOLON_TOK
%token <string> ID_FUNCTION
%token <string> ID_PARAMETER
%token <string> PLUS_TOK
%token <string> MULT_TOK
%token <number> NUMBER


%% 

commands:
        | commands command
        ;


command:
        function_definition | function_call ;

/* Paring of the function definition grammar */
function_definition:
        FUNCTION_TOK ID_FUNCTION list_of_parameters CLOSE_PAR_TOK OPEN_BRACES_TOK RETURN_TOK operations SEMICOLON_TOK CLOSE_BRACES_TOK
        {
            functions[i_function].name = $2;
            if(!checkFunctionDef(&functions[i_function], &functions))
            {
                printf("\nERROR: The function is not correctly defined!\n");
                functions[i_function] = emptyStruct;
            }
            else
            {
                printf("\nFunction correctly defined!\n");
                i_function++;
            }

            i_par_def = 0;
            i_par_call = 0;
            i_op = 0;
        }
;

/* Stored parameters & operators in three vectors, and we increment the relative indexes */
list_of_parameters:
    ID_PARAMETER 
    {
        functions[i_function].parameters_def[i_par_def] = $1;
        i_par_def ++;  
    }
    |    
    list_of_parameters COMMA_TOK ID_PARAMETER  
    {
        functions[i_function].parameters_def[i_par_def] = $3;
        i_par_def ++; 
    }
;

operations:
    ID_PARAMETER
    {
        functions[i_function].parameters_call[i_par_call] = $1;
        i_par_call++;
    }
    |
    operations PLUS_TOK ID_PARAMETER  
    {
        functions[i_function].parameters_call[i_par_call] = $3;
        functions[i_function].operators[i_op] = $2;

        i_par_call++;
        i_op++;
    }
    |
    operations MULT_TOK ID_PARAMETER  
    {
        functions[i_function].parameters_call[i_par_call] = $3;
        functions[i_function].operators[i_op] = $2;
       
        i_par_call++;
        i_op++;
    }
;


/* Paring of the function call grammar */
function_call:
    ID_FUNCTION list_of_numbers CLOSE_PAR_TOK SEMICOLON_TOK
    {
        if(functionCall(&functions, &passed_parameters, $1, i_passed_parameters, &call_result))
        {
            printf("\nResult:\t %f\n", call_result);
        }
        else
        {
            printf("\nERROR: The call is not correct!\n");
        }
        i_passed_parameters = 0;
        memset(passed_parameters, 0, sizeof passed_parameters); // clear array
    } 

/* Stored the values of the parameters in a vector & we incremet the index */
list_of_numbers:
    NUMBER 
    {
        passed_parameters[i_passed_parameters] = $1;
        i_passed_parameters ++;
    }
    |    
    list_of_numbers COMMA_TOK NUMBER  
    {
        passed_parameters[i_passed_parameters] = $3;
        i_passed_parameters ++;     
    }
;



%%
void yyerror(const char *str)
{
        fprintf(stderr,"ERROR: %s\n",str);
}

int yywrap()
{
        return 1;
}

main()
{
    char mychr;
    do{

        printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
        printf("\n\n                             1: Instructions  \n");
        printf("\n\n                             2: Start             \n ");
        printf("\n\n                             0: Exit              \n ");
        printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");

        mychr = getchar();
        system( "clear" );
        switch(mychr)
        {
            case '1':
                system( "clear" );

                printf("EXAMPLE FUNCTION DEFINITION:");
                printf("\n\nfunction f1(a,b,c)\n{\n    return a*b+c*a*b;\n}");
                printf("\n\nOR:");
                printf("\n\nfunction f1(a,b,c){\n    return a*b+c*a*b;\n}");

                printf("\n\nEXAMPLE FUNCTION CALL:");
                printf("\n\nf1(1.0,2.0,3.0);");
            break; 

            case '2':
                yyparse();
            break; 

            case '0':
                    system( "clear" );
                    exit(0);
            break;


        }
    }while(mychr!='0');

}


