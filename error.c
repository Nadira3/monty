#include "monty.h"
/**
 * usage_check - checks for program usage error
 * @arg_count: argument count
 * @file: file stream
 * @path: file name including path
 */
void usage_check(int arg_count, FILE *file, char *path)
{
	char *filename = NULL, *err_msg = NULL;

	if (arg_count != 2)
	{
		err_msg = "USAGE: monty file\n";
		fprintf(stderr, "%s\n", err_msg);
		exit(EXIT_FAILURE);
	}
	filename = basename(path);
	if (!file)
	{
		err_msg = "Error: Can't open file ";
		fprintf(stderr, "%s%s\n", err_msg, filename);
		exit(EXIT_FAILURE);
	}
}
/**
 * free_buf - frees a multidimensional array
 * @input_token; array
 */
void free_buf(char **input_token)
{
	int i = 0;

	while (input_token[i])
		free(input_token[i++]);
	free(input_token);
}
