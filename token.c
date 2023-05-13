#include "monty.h"
#include "main.c"

/**
 * 
 * 
 * 
*/
		void push(stack_t **head, int lineCounter, char *token)
{
	stack_t *h = NULL;
	bool isPush = false;
	char *buffer;

	while (token != NULL)
	{
		if (isPush == 1)
		{
			push(&h, lineCounter, token);
			isPush = false;
			token = strtok(NULL, DELIM);
			lineCounter++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			isPush = true;
			token = strtok(NULL, DELIM);
			continue;
		}
		else
		{
			if (opcodeFunc(token) != NULL)
				opcodeFunc(token)(&h, lineCounter);
			else
			{
				freeList (&h);
				fprintf(stderr, "L%d: unknown instruction %s\n", lineCounter, token);
				exit (EXIT_FAILURE);
			}
		}
		lineCounter++;
		token = strtok(NULL, DELIM);
	}
}
