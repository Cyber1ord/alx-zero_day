#include "monty.h"

/**
 * nop - does literally nothing
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int nline)
{
    if (stack == NULL || *stack == NULL)
	{
        fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
        exit(EXIT_FAILURE);
    }

    int c = (*stack)->n;
    if (!isalpha(c))
	{
        fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (char)c);
}


/**
 * pstr - prints a str from ascii starting from the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pstr(stack_t **stack, unsigned int nline)
{
    stack_t *temp = *stack;
    (void)nline;

    while (temp)
	{
        if (temp->n == 0 || !isalpha(temp->n))
            break;
        
        putchar(temp->n);
        temp = temp->next;
    }
    putchar('\n');
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
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;

    while (current)
	{
        stack_t *temp = current->next;
        free(current);
        current = temp;
    }

    *stack = NULL;
}

