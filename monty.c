#include "monty.h"
/**
 * main - entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: exit status of the program
 */
int main(int ac, char **av)
{
	size_t line_number = 1;
	ssize_t input_len = 0;
	char *input = NULL, **input_token = NULL;
	FILE *file = fopen(av[1], "r");
        void (*opf)(stack_t **stack, unsigned int line) = NULL;

	usage_check(ac, file, av[1]);

	while (input_len != -1)
	{
		input = read_input(file, &input_len);
		if (input_len == -1)
			break;
		input_token = parse_input(input, file);
		opf = get_func(input, input_token, file, line_number);
		free(input);
		free_buf(input_token);
		line_number++;
	}
	free(input);
	fclose(file);
	return (0);
}
