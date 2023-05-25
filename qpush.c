#include "monty.h"

/**
 * qpush - pushes for queue instead of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void qpush(stack_t **n_stack, unsigned int nline)
{
	stack_t *last, *new;

	if (n_stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(n_stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*n_stack)
	{
		last = *n_stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*n_stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
