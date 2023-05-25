#include "monty.h"

/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
	size_t size = 0;
	meta_t *meta = NULL;
	line_t line;

	meta = malloc(sizeof(meta_t));
	if (!meta)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.content = NULL;

	meta->file = file;
	meta->n_stack = NULL;
	meta->buf = NULL;

	while (getline(&(meta->buf), &size, meta->file) != -1)
	{
		line.number++;
		parseline(&line, meta->buf);
		if (line.content)
			get_op_func(line, meta)(&(meta->n_stack), line.number);
	}

	free(meta->buf);
	free_stack(&(meta->n_stack));
	fclose(meta->file);
	free(meta);
}
