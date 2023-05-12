#include "monty.h"

/**
 *push - pushes a new node onto the top of the stack
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void push(stack_t **stack, unsigned int line_number, char *token)
{
	int digit;
	stack_t *newNode;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	digit = atoi(token);
	
	if (strspn(token, "0123456789+-") != strlen(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = digit;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
