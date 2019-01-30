#include<stdio.h>
#include<string.h>
#include <stdbool.h>

#define N 50	//Maximum lenght of a string
#define M 50	//Maximum number of parameters in a function

typedef char string[N];

typedef struct Function_definition
{
	char *name;
	char *parameters_def[M];		//Paramets of the function
	char *parameters_call[2*M];		//List of ordered parameters called in 
	char *operators[M-1]; 			//List of operators in the function definition
}function_definition;

bool checkFunctionDef(function_definition* f, function_definition *f_list);
bool functionCall(function_definition *f, float *passed_parameters, char* id_function, int dim_passed_parameters, float *call_result);