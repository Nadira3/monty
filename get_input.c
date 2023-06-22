#include "monty.h"

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
			err_and_exit(input, NULL, "s", "Error: malloc failed");
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
				err_and_exit(input, input_token, "s", "Error: malloc failed");
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

/**
 * opcode_check - checks the validity of an instruction
 * @command: opcode instruction
 * Return: function pointer
 *
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
}*/
