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

	*input_len = getline(&(var.input), &input_size, file);
	if (*input_len == - 1 && !(feof(file)))
		exit(EXIT_FAILURE);
	if (!(feof(file)))
		(var.input)[*input_len - 1] = '\0';
	return (var.input);
}
/**
 * parse_input - tokenizes an input
 * @input: command line
 * Return: command - argument pair, null terminated
 */
char **parse_input(void)
{
	char *str_token = NULL, *ptr = NULL;
	size_t i = 0, len = 0;

	if (var.input)
	{
		var.input_token = malloc(sizeof(char*) * 3);
		if (!(var.input_token))
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(var.input);
			exit(EXIT_FAILURE);
		}
		ptr = var.input;
		while (*ptr && *ptr == ' ')
			ptr++;
		str_token = strtok(ptr, " ");
		while (i < 2 && str_token)
		{
			len = strlen(str_token);
			(var.input_token)[i] = malloc(len + 1);
			if (!(var.input_token[i]))
			{
				fprintf(stderr, "Error: malloc failed\n");
				(var.input_token)[i] = NULL;
				free_buf(var.input_token);
				free(var.input);
				exit(EXIT_FAILURE);
			}
			strncpy((var.input_token)[i], str_token, len);
			(var.input_token)[i][len] = '\0';
			while (*ptr && *ptr == ' ')
				ptr++;
			str_token = strtok(NULL, " ");
			i++;
		}
		(var.input_token)[i] = NULL;
	}
	return (var.input_token);
}
/**
 * opcode_check - checks the validity of an instruction
 * @command: opcode instruction
 * Return: function pointer
 */
void (*opcode_check(char *command))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instruction[] = {
		{"add", add_func},
		{"push", push_func},
		{"pop", pop_func},
		{"pint", pint_func},
		{"pall", pall_func},
		{"nop", nop_func},
		{"swap", swap_func},
		{NULL, NULL}
	};

	if (command)
	{
		while(instruction.opcode[i])
		{
			if (!(strcmp(command, instruction.opcode[i])))
				return (instruction.f[i]);
			i++;
		}
	}
	return (instruction.f[i]);
}
