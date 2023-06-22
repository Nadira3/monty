#include "monty.h"
/**
 * main - entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: exit status of the program
 */
int main(int ac, char **av)
{
	ssize_t input_len = 0;
	char *input = NULL, **input_token = NULL;
	FILE *file = fopen(av[1], "r");
	int i = 0, line_number = 1;

	usage_check(ac, file, av[1]);

	while (input_len != -1)
	{
		input = read_input(file, &input_len);
		if (input_len == -1)
			break;
		printf("%ld\n", input_len);
		input_token = parse_input(input);
		/* execute(input_token); */
		free(input);
		free_buf(input_token);
	}
	free(input);
	fclose(file);
	return (0);
}
