#include<stdio.h>
#include<string.h>
#include "functionParser.h"

/* 
	When defininf a function we check for the following errors:
		- If the choosen function name is arleady used
		- Name of the paraters between parenthesis
		- If the name of the parameters in the definition and in the body match

	Inputs of the function:
		- *f: function we are defining
		- *f_list: vector of function definitions

	Output:
		- true: correct definition of the function
		- false: error on the definition
*/ 
bool checkFunctionDef(function_definition* f, function_definition *f_list)
{
	int i = 0, j = 0, flag = 0;
	
	// Check if the name of the function is arleady used
	while(f_list[i].name != NULL)
	{
		if(strcmp(f_list[i].name, f->name) == 0)
		{
			flag++;	// count how many time the function name is repeated
		}
		i++;
	}
	if(flag != 1)
	{
		printf("\nERROR: Name of the function arleady used!");
		return false;
	}

	/* Look if the name of the parameters is unique*/
	i = 0;
	while(f->parameters_def[i] != NULL)
	{
		j = 0;
		flag = 0;
		while(f->parameters_def[j] != NULL)
		{
			if(strcmp(f->parameters_def[i], f->parameters_def[j]) == 0)
				flag++; 	// count how many time the parameter name is repeated
			j++;
		}
		if(flag != 1)
		{
			printf("\nERROR: Name of the parameters is not unique in the definition!");
			return false;
		}
		i++;
	}

	/* Look if the used parameters are the same as the one in the def*/
	while(f->parameters_call[i] != NULL)
	{
		j = 0;
		flag = 0;
		while(f->parameters_def[j] != NULL)
		{
			if(strcmp(f->parameters_call[i], f->parameters_def[j]) == 0)
				flag++; 	// count if we match a parameter
			j++;
		}
		if(flag == 0)
		{
			printf("\nERROR: Use of an undecleared parameter!");
			return false;
		}
		i++;
	}
	return true;
}

/* 
	When calling a function we do the following:
		- Check if the number of passed parameters is equal to the one of the definition
		- Compute & return the result

	Inputs of the function:
		- *f_list: vector of function definitions
		- *passed_parameters: vector of parameters value
		- id_function: name of the function
		- dim_passed_parameters: number of elements in vector of parameters value
		- call_result: pointer to the result

	Output:
		- true: correct call of the function
		- false: error on the call
*/ 
bool functionCall(function_definition *f_list, float *passed_parameters, char* id_function, int dim_passed_parameters, float *call_result)
{
	int i = 0, index_fun = -1;

	// Check if the function we are calling has been arleady defined
	while(f_list[i].name != NULL)
	{
		if(strcmp(f_list[i].name , id_function) == 0)
			index_fun = i; // index of the function we are calling
		i++;
	}

	if(index_fun == -1)
	{
		printf("\nERROR: Function not defined!");
		return false;
	}

	// Count how many parameters does .parameters_def[] has & check if it's equal to the number of passed values
	i = 0;
	while(f_list[index_fun].parameters_def[i] != NULL)
	{
		i++;
	}

	if(i != dim_passed_parameters)
	{
		printf("\nERROR: The number of parameters of the call is not equal to the definition!");
		return false;
	}


	// Save the values correspondent to the parameter in the body in a temporary array ordered by the usage in the body
	i = 0;
	int j = 0, index_op = 0, index_par;
	float temp[2*M]; 
	int dim_par_value;

	while(f_list[index_fun].parameters_call[i] != NULL)
	{
		j = 0;
		while(f_list[index_fun].parameters_def[j] != NULL)
		{
			if(strcmp(f_list[index_fun].parameters_call[i], f_list[index_fun].parameters_def[j]) == 0)
				index_par =  j;
			j++;
		}

		temp[i] = passed_parameters[index_par];
		i++;
	}
	dim_par_value = i;

	/*  We execute multiplication first by multipling two by two the elements that are to be multiplied. We set to zero the left element.
		Example:
		a+b*c+a
		[a b c d a]
		[a 0 bc a] 
	*/
	i = 0;
	while(f_list[index_fun].operators[i] != NULL)
	{
		if(strcmp(f_list[index_fun].operators[i], "*") == 0)
		{
			temp[i+1] = temp[i]*temp[i+1];
			temp[i] = 0;
		}
		
		i++;
	}
	// We sum up all the elements in the temporary array
	float result = 0;
	for(i = 0; i<dim_par_value; i++)
	{
		result = result + temp[i];
	}
	*call_result = result;

	return true;
}