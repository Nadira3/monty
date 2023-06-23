#include "monty.h"

/**
 * main - entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: exit status of the program
 */
int main(int ac, char **av)
{
	size_t line_number = 1, flag = 0;
	ssize_t input_len = 0;
	char *input = NULL, **input_token = NULL;
	FILE *file = ac < 2 ? NULL : fopen(av[1], "r");
	void (*opf)(stack_t **stack, unsigned int line_number) = NULL;

	usage_check(ac, file, av[1]);

	stack = NULL;
	while (input_len != -1)
	{
		input = read_input(file, &input_len);
		if (feof(file))
			break;
		input_token = parse_input(input, file);
		if (!*input_token)
		{
			free(input);
			free(input_token);
			line_number++;
			continue;
		}
		opf = g(input, input_token, file, line_number);
		if (input_token[1])
			n = atoi(input_token[1]);
		opf(&stack, line_number);
		free(input);
		free_buf(input_token);
		line_number++;
	}
	free(input);
	fclose(file);
	free_stack(&stack);
	return (0);
}
