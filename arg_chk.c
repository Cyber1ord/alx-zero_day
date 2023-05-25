#include "monty.h"

/**
 * arg_chk - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool arg_chk(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}