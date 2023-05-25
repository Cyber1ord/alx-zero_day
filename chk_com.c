#include "monty.h"

arg_t arg = {0, 0};

/**
 * chk_com - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool chk_com(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}