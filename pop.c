#include "monty.h"

/**
 * pop - removes the top element of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pop(stack_t **n_stack, unsigned int nline)
{
	if (n_stack == NULL || *n_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}
	/* if stack is more than 1 node, else free entire thing */
	if ((*n_stack)->next != NULL)
	{
		*n_stack = (*n_stack)->next;
		free((*n_stack)->prev);
		(*n_stack)->prev = NULL;
	}
	else
	{
		free(*n_stack);
		*n_stack = NULL;
	}
}