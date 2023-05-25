#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void push(stack_t **n_stack, unsigned int nline)
{
	stack_t *new;

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

	new->next = *n_stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*n_stack)
		(*n_stack)->prev = new;
	*n_stack = new;
}