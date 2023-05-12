#include "monty.h"


/**  
*pint -   prints the value at the top of the stack,
*@stack: double pointer to the head  of the stack
*@line_number: Line number of the opcode in the monty file
*/

 void pint(stack_t **stack, unsigned int line_number)
{

  /* Vérifier si le stack est vide */
  if (*stack == NULL)
  {
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    exit(EXIT_FAILURE);
  }

  /* Imprimer la valeur au sommet de la pile */
  printf("%d\n", (*stack)->n);
}
