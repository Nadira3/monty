#include "monty.h"
/**
 * execute - executes a command line
 * @input_token: array of arguments
 * @line_number: line number of instruction
 * @input: command line
 * Return: 0 if sucessful, 1 otherwise
 */
int execute(size_t line_number)
{
	void (*stack_func)(stack_t **stack, unsigned int line_number) = NULL;

	stack_func = opcode_check((var.input_token)[0]);
	if (!stack_func)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, (var.input_token)[0]);
		free_buf(var.input_token);
		free(var.input);
		exit(EXIT_FAILURE);
	}
	stack_func(stack, line_number);
}

stack_t *create_node(void)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_buf(var.input_token);
		free(var.input);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi((var.input_token)[1]);
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
