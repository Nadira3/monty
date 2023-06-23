#include "monty.h"

/**
 * read_input - reads a line of input from a file
 * @file: file stream
 * @input_len: number of characters read from a line
 * Return: buffer containing characters read from the file
 */
char *read_input(FILE *file, ssize_t *input_len)
{
	size_t input_size = 0;
	char *input = NULL;

	*input_len = getline(&input, &input_size, file);
	if (*input_len == -1 && !(feof(file)))
		exit(EXIT_FAILURE);
	if (!(feof(file)))
		input[*input_len - 1] = '\0';
	return (input);
}

/**
 * parse_input - tokenizes an input
 * @input: command line
 * @f: file
 * Return: command - argument pair, null terminated
 */
char **parse_input(char *input, FILE *f)
{
	char *str_token = NULL, *ptr = NULL;
	char **input_token = NULL;
	size_t i = 0, len = 0;

	if (input)
	{
		input_token = malloc(sizeof(char *) * 3);
		if (!input_token)
			err_and_exit(input, NULL, f, "s", "Error: malloc failed");
		ptr = input;
		while (*ptr && *ptr == ' ')
			ptr++;
		str_token = strtok(ptr, " ");
		while (i < 2 && str_token)
		{
			len = strlen(str_token);
			input_token[i] = malloc(len + 1);
			if (!(input_token[i]))
			{
				input_token[i] = NULL;
				err_and_exit(input, input_token, f, "s", "Error: malloc failed");
			}
			strncpy(input_token[i], str_token, len);
			input_token[i][len] = '\0';
			str_token = strtok(NULL, " ");
			i++;
		}
		input_token[i] = NULL;
	}
	return (input_token);
}
