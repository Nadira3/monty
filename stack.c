#include "monty.h"

/**
 * free_buf - frees a multidimensional array
 * @input_token: array
 */
void free_buf(char **input_token)
{
	int i = 0;

	if (input_token)
	{
		while (input_token[i])
			free(input_token[i++]);
		free(input_token);
	}
}

/**
 * free_stack - frees a stack
 * @stack: stack
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (*stack)
	{
		ptr = ptr->next;
		free(*stack);
		*stack = ptr;
	}
}

/**
 * stack_len - finds the length of a stack
 * Return: stack length
 */
int stack_len(void)
{
	int count = 0;
	stack_t *ptr = stack;

	if (stack)
	{
		while (ptr)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return (count);
}
