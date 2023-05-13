#include "monty.h"

/**
 * findOpCode - matches the opcode to the appropriate function
 * @opcode: pointer to opcode that is to be matched
 * @stack: pointer to pointer to top of the stack
 * @line_number: line number of read line

 */
void (*opcodeFunc(char *opCode))(stack_t **stack, unsigned int line_number)
{
	int index = 0;
	instruction_t instructions[] = {
		{"pint", pint},
		{"pop", pop},
		{"pall", pall},
		{"nop", nop},
		{NULL, NULL}
	};

	while (instructions[index].opcode != NULL)
	{
		if (strcmp(opCode, instructions[index].opcode) == 0)
			return (instructions[index].f);

		index++;
	}
	return (NULL);
}
