#include "monty.h"
/**
 * main - entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: exit status of the program
 */
int main(int ac, char **av)
{
	FILE *file = fopen(av[1], "r");
	ssize_t input_len = 0;
	size_t i = 0, line_number = 1;
	global_t var
	{
		char *input = NULL;
		char **input_token = NULL;
		stack_t *head = NULL;
	};

	usage_check(ac, file, av[1]);

	while (input_len != -1)
	{
		var.input = read_input(file, &input_len);
		if (input_len == -1)
			break;
		var.input_token = parse_input();
		execute(line_number);
		free(var.input);
		free_buf(var.input_token);
	}
	free(var.input);
	fclose(file);
	return (0);
}
