#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotl(stack_t **n_stack, unsigned int nline)
{
	stack_t *tmp;
	int hold_this, hold_this_again;
	(void)nline;

	if (n_stack == NULL || *n_stack == NULL)
	{
		nop(n_stack, nline);
	}

	hold_this = (*n_stack)->n;
	tmp = *n_stack;

	while (tmp)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}

	hold_this_again = tmp->n;
	(*n_stack)->n = hold_this_again;
	tmp->n = hold_this;
}

/**
 * rotlop - rotates stack to left
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotlop(stack_t **n_stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!n_stack || !(*n_stack) || !((*n_stack)->next))
		return;

	tmp = *n_stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = tmp;
	tmp->prev = last;
	tmp->next->prev = NULL;
	*n_stack = tmp->next;
	tmp->next = NULL;
}

/**
 * rotrop - rotates stack to right
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotrop(stack_t **n_stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!n_stack || !(*n_stack) || !((*n_stack)->next))
		return;

	tmp = *n_stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	tmp->prev = last;
	last->next = tmp;
	*n_stack = last;
}
