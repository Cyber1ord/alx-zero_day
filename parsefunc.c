#include "monty.h"

/**
 * parseline - tokenizes a line of text, storing it in line struct
 * @line: struct containing line contents and line number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void parseline(line_t *line, char *buffer)
{
    unsigned int i = 0;
    char *token = NULL;
    const char delimiters[] = " '\n'";

    line->content = malloc(sizeof(char *) * 3);
    if (!line->content)
	{
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer, delimiters);
    while (token && i < 2)
	{
        line->content[i++] = token;
        token = strtok(NULL, delimiters);
    }

    line->content[i] = NULL;
}


/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
    size_t size = 0;
    meta_t *meta = malloc(sizeof(meta_t));
    if (!meta)
	{
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    meta->file = file;
    meta->stack = NULL;
    meta->buf = NULL;

    line_t line = { .number = 0, .content = NULL };

    while (getline(&meta->buf, &size, meta->file) != -1) {
        line.number++;
        parseline(&line, meta->buf);
        if (line.content)
            get_op_func(line, meta)(&meta->stack, line.number);
    }

    free(meta->buf);
    free_stack(&meta->stack);
    fclose(meta->file);
    free(meta);
}

