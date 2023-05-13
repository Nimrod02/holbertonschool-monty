#include "monty.h"

/**
 * free_dlistint - main function that free the list
 * @head: head pointer, start of the list
 *
*/

void freeList(stack_t **h)
{
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}

