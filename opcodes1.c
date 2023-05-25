#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int nline)
{
    if (stack == NULL)
	{
        fprintf(stderr, "L%d: stack not found\n", nline);
        exit(EXIT_FAILURE);
    }

    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    new->next = *stack;
    new->prev = NULL;
    new->n = arg.arg;
    
    if (*stack != NULL)
	{
        (*stack)->prev = new;
    }
    
    *stack = new;
}


/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int nline)
{
    stack_t *temp = *stack;
    (void)nline;

    while (temp != NULL)
	{
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}


/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int nline) {
    if (stack == NULL || *stack == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}


/**
 * pop - removes the top element of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int nline) {
    if (stack == NULL || *stack == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}


/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int nline) {
    if (stack == NULL || *stack == NULL || !((*stack)->next)) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
        exit(EXIT_FAILURE);
    }

    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

