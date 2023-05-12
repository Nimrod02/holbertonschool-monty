#include "monty.h"

/**
*pall - function prints all the values on the stack
*@stack: double pointer to the head  of the stack
*@line_number: not used
*/
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		fprintf(stderr, "%d\n", current->n);
		current = current->next;
	}
}
