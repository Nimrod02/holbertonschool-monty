#include "monty.h"

/**
 * push - function that add an element to a stack
 * 
 * 
 * 
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = malloc(sizeof (stack_t));

	int success = ptr != NULL;

	if (success)
	{
		ptr->n = line_number;
		ptr->next = *stack;
		ptr->prev = NULL;
		*stack = ptr;
	}

	return (success);
}


// /**
//  *pall - 
//  * 
//  * 
// */

// void pall(stack_t **stack, unsigned int line_number)
// {


// }

// /**
//  *pint -  
//  * 
//  * 
//  * 
// */

// void pint(stack_t **stack, unsigned int line_number)
// {


// }

