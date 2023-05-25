#include "monty.h"

/**
 * addop - adds the top two elements together
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void addop(stack_t **n_stack, unsigned int nline)
{
	stack_t *tmp;

	if (!(*n_stack) || !(*n_stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	tmp = *n_stack;
	(*n_stack)->next->n += (*n_stack)->n;
	*n_stack = (*n_stack)->next;
	(*n_stack)->prev = NULL;
	free(tmp);
}