#include "monty.h"

/**
 * push - function that add an element to a stack
 *@stack: double pointer to the head  of the stack
 *@line_number: Line number of the opcode in the Monty file
*/

void push(stack_t **stack, unsigned int line_number)


{
	stack_t *new_node;
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Erreur lors de l'allocation de mémoire\n");
		exit(EXIT_FAILURE);
	}
	if (line_number != 0)
	
	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;
	
	if (*stack != NULL)
	(*stack)->prev = new_node;
	
	*stack = new_node;
}





