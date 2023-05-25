#include "monty.h"

/**
 * mulop - multiplies the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void mulop(stack_t **n_stack, unsigned int nline)
{
	stack_t *tmp;

	if (!(*n_stack) || !(*n_stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	tmp = *n_stack;
	(*n_stack)->next->n *= (*n_stack)->n;
	*n_stack = (*n_stack)->next;
	(*n_stack)->prev = NULL;
	free(tmp);
}