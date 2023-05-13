#include "monty.h"

/**
 * add - add top two nodes of the stack
 * @stack: top of the list
 * @lineNumber: line number
*/

void add(stack_t **stack, unsigned int lineNumber)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", lineNumber);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n += (*stack)->n;

        (*stack) = (*stack)->next;

        free((*stack)->prev);

        (*stack)->prev = NULL;
}

