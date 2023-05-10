#include "monty.h"

/**
 *opcode_funct - find the good function 
 *@opcode: pointer to opcode that is to be matched
 *@stack: pointer to pointer 
 *@line_number: line number to read 
 */

void opcode_funct(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

}