#include "monty.h"

/**
 * add - add top two nodes of the stack
 * @stack: top of the list
 * @lineNumber: line number
*/
void add(stack_t **stack, unsigned int lineNumber)
{
        /* Vérifie si la pile est vide ou a un seul élément */
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", lineNumber);
                exit(EXIT_FAILURE);
        }

        /* Ajoute la valeur du premier élément à la valeur du deuxième élément */
        (*stack)->next->n += (*stack)->n;

        /* Déplace le pointeur du sommet de la pile vers le deuxième élément */
        (*stack) = (*stack)->next;

        /* Libère la mémoire de l'ancien premier élément */
        free((*stack)->prev);

        /* Met à jour le pointeur vers le précédent du nouveau premier élément */
        (*stack)->prev = NULL;
}
