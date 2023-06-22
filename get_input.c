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
	if (*input_len == - 1 && !(feof(file)))
		exit(EXIT_FAILURE);
	if (!(feof(file)))
		input[*input_len - 1] = '\0';
	return (input);
}
/**
 * parse_input - tokenizes an input
 * @input: command line
 * Return: command - argument pair, null terminated
 */
char **parse_input(char *input)
{
	char *str_token = NULL, *ptr = NULL;
	char **input_token = NULL;
	size_t i = 0, len = 0;

	if (input)
	{
		input_token = malloc(sizeof(char*) * 3);
		if (!input_token)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (NULL);
		}
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
				fprintf(stderr, "Error: malloc failed\n");
				input_token[i] = NULL;
				free_buf(input_token); /* write your free func */
				return (NULL);
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

void (*opcode_check(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"add", add},
		{"push", push},
		{"pop", pop},
		{"pint", pint},
		{"pall", pall},
		{"nop", nop},
		{"swap", swap},
		{NULL, NULL}
	}
}
