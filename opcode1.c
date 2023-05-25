#include "monty.h"

/**
 * nop - does literally nothing
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void nop(stack_t **n_stack, unsigned int nline)
{
	(void)n_stack;
	(void)nline;
}

/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pchar(stack_t **n_stack, unsigned int nline)
{
	char c;
	stack_t *tmp;

	if (n_stack == NULL || *n_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	tmp = *n_stack;
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}

	c = tmp->n;
	if (_isalpha(tmp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - prints a str from ascii starting from the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pstr(stack_t **n_stack, unsigned int nline)
{
	int idx = 0;
	char res[] = "";
	char c;
	stack_t *tmp;

	tmp = *n_stack;
	(void)nline;
	/* starts at the top */
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (_isalpha(tmp->n) == 0)
			break;
		c = tmp->n;
		printf("%c", c);
		res[idx] += c;
		tmp = tmp->next;
		idx++;
	}
	printf("\n");
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}

/**
 * free_stack - frees all nodes in a stack
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing.
 */
void free_stack(stack_t **n_stack)
{
	stack_t *tmp = NULL;

	if (n_stack == NULL || *n_stack == NULL)
		return;

	while (*n_stack != NULL)
	{
		tmp = (*n_stack)->next;
		free(*n_stack);
		*n_stack = tmp;
	}
}
