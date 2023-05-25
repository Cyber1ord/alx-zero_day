#include "monty.h"


/**
 * push_chk - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @meta: struct containing all allocated memory
 *
 * Return: Nothing.
 */
void push_chk(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !arg_chk(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(meta->buf);
		free_stack(&(meta->n_stack));
		fclose(meta->file);
		free(meta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}
