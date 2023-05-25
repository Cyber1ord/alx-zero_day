#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int nline)
{
    if (stack == NULL || *stack == NULL)
	{
        nop(stack, nline);
    }

    int hold_this = (*stack)->n;
    stack_t *temp = *stack;

    while (temp->next)
	{
        temp = temp->next;
    }

    int hold_this_again = temp->n;
    (*stack)->n = hold_this_again;
    temp->n = hold_this;
}


/**
 * rotlop - rotates stack to left
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotlop(stack_t **stack, unsigned int nline)
{
    (void)nline;
    if (!stack || !(*stack) || !((*stack)->next))
        return;

    stack_t *last = *stack;
    while (last->next)
	{
        last = last->next;
    }

    last->next = *stack;
    (*stack)->prev = last;
    (*stack)->next->prev = NULL;
    *stack = (*stack)->next;
    (*stack)->next = NULL;
}


/**
 * rotrop - rotates stack to right
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotrop(stack_t **stack, unsigned int nline)
{
    (void)nline;
    if (!stack || !(*stack) || !((*stack)->next))
        return;

    stack_t *last = *stack;
    while (last->next)
	{
        last = last->next;
    }

    last->prev->next = NULL;
    last->prev = NULL;
    (*stack)->prev = last;
    last->next = *stack;
    *stack = last;
}

