#include "monty.h"

/**
 *main - function use all function
 *@argc: counter of argument
 *@argv: value of argument
 *freeList - function free the stack 
 *return: return succes or fail
 *@h: pointer to pointer of struct stack_t
*/

int main(int argc, char *argv[])
{

	stack_t *h = NULL;
	int fileOpen, fileContent, lineCounter;
	bool isPush = false;
	char *buffer, *token;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileOpen = open(argv[1], O_RDONLY);

	if (fileOpen == -1)
	{
		fprintf(stderr, "Error: can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 17000);
	if (buffer == NULL)
	{

		fprintf(stderr, "Error: malloc failed");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	fileContent = read (fileOpen, buffer, 10000);

	if (fileContent == -1)
	{
		free (buffer);
		close (fileOpen);
		exit (EXIT_FAILURE);
	}
	
	token = strtok(buffer, DELIM);

	lineCounter = 1;
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

	freeList (&h);
	free (buffer);
	close(fileOpen);

	return (EXIT_SUCCESS);
}
