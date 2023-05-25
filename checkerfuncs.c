#include "monty.h"

arg_t arg = {0, 0};

/**
 * comment_check - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool comment_check(line_t line)
{
    if (strlen(line.content) == 0)
	{
        free(line.content);
        return true;
    }

    if (line.content[0] == '#')
	{
        free(line.content);
        return true;
    }

    return false;
}

/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool argument_check(char* token)
{
	unsigned int i;

    if (!token)
	{
        return false;
    }

    if (token[0] == '-')
	{
        return true;
    }

    for (i = 0; token[i]; i++)
	{
        if (token[i] < '0' || token[i] > '9')
		{
            return false;
        }
    }

    return true;
}

/**
 * push_check - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @meta: struct containing all allocated memory
 *
 * Return: Nothing.
 */
void push_check(line_t line, meta_t* meta, const char* opcode)
{
    if ((strcmp(opcode, "push") == 0) && !argument_check(line.content[1]))
	{
        fprintf(stderr, "L%d: usage: push integer\n", line.number);
        free(line.content);
        free(meta->buf);
        exit(EXIT_FAILURE);
    } 
	else if (strcmp(opcode, "push") == 0)
	{
        argument_t arg;
        arg.arg = atoi(line.content[1]);
    }
}
