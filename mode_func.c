#include "monty.h"

/**
 * addst - changes mode of push to stack
 * @stack: pointer to stack
 * @nline: line number
 *
 * Return: Nothing.
 */
void addst(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
 * addqu - changes mode of push to queue
 * @stack: pointer to stack
 * @nline: line number
 *
 * Return: Nothing.
 */
void addqu(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 1;
}

/**
 * qpush - pushes for queue instead of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *last, *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
