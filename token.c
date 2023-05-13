#include "monty.h"
#include "main.c"

/**
 * 
 * 
 * 
*/
		void TOKEN(stack_t **h)
{
	int lineCounter;
	bool isPush = false;
	char *buffer, *token;

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
