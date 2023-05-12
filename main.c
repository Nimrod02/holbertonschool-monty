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
	int fileOpen, fileContent, lineCounter, index = 0;
	bool isPush = false;
	char *buffer, *token;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

		fileOpen = open(argv[1], O_RDONLY);

		if (fileOpen == -1)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		buffer = malloc(sizeof(char) * 1024);
		if (buffer == NULL)
		{

			printf("Error: malloc failed");
			free(buffer);
			exit(EXIT_FAILURE);
		}

	fileContent = read (fileOpen, buffer, 1024);

	if (fileContent = -1)
	{
		free (buffer);
		close (fileOpen);
		exit (EXIT_FAILURE);
	}
	
	token = strtok(buffer, DELIM);

	buffer = strtok(NULL, DELIM);

		while (token != NULL)
		{
			if (isPush == true)
		{
			isPush = false;
			token = strtok(NULL, DELIM);
			push (&h, lineCounter, token);
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
			if (opcodeFunc(token) != 0)
				opcodeFunc(token)(&h, lineCounter);
			else
			{
				freelist (&h);
				printf("%d : usage: push integer", lineCounter, token);
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
